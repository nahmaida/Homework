import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Query database for stocks owned
    stocks = db.execute(
        "SELECT stock, quantity FROM owned WHERE user_id=?", session["user_id"])

    # Get amount of cash owned by user
    cash = db.execute("SELECT cash FROM users WHERE id=?",
                      session["user_id"])[0]["cash"]

    # Initialize total money owned by user to cash
    user_total = cash

    # Add price and total to list of stocks
    for stock in stocks:
        price = lookup(stock["stock"])["price"]
        total = stock["quantity"] * price
        user_total += total  # Increment user total money bu price of stock
        stock.update({"price": price, "total": total})

    # Render stocks owned
    return render_template("index.html", stocks=stocks, cash=cash, user_total=user_total)


@app.route("/add", methods=["GET", "POST"])
@login_required
def add():
    """Add cash to user"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure amount was submitted
        amount = request.form.get("amount")
        if not amount:
            return apology("must provide symbol", 403)

        # Ensure amount is positive number
        elif not amount.isnumeric() or float(amount) < 1:
            return apology("invalid amount", 403)
        amount = float(amount)

        # Add stock price to user's cash
        cash = db.execute("SELECT cash FROM users WHERE id=?",
                          session["user_id"])[0]["cash"]
        db.execute("UPDATE users SET cash=? WHERE id=?",
                   cash + amount, session["user_id"])

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("add.html")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        shares = request.form.get("shares")
        symbol = request.form.get("symbol")

        # Ensure symbol was submitted
        if not symbol:
            return apology("must provide symbol", 403)

        # Ensure number of shares was submitted
        elif not shares:
            return apology("must provide number of shares", 403)

        shares = shares.strip()
        symbol = symbol.strip().upper()

        # Ensure number of shares is a positive integer
        if not shares.isdecimal() or int(shares) < 1 or int(shares) != float(shares):
            return apology("invalid number of shares", 400)
        shares = int(shares)

        # Query database for symbol
        values = lookup(symbol)

        # Ensure stock exists
        if not values:
            return apology("invalid symbol", 400)

        # Get total stock price
        value = values["price"] * float(shares)

        # Check if user can afford stock
        cash = db.execute("SELECT cash FROM users WHERE id=?",
                          session["user_id"])[0]["cash"]

        if value > cash:
            return apology("can't afford", 400)

        # Increment number of shares if already owned, else create row
        number = db.execute("SELECT quantity FROM owned WHERE stock=? AND user_id=?",
                            symbol, session["user_id"])
        if number:
            db.execute("UPDATE owned SET quantity=? WHERE stock=? AND user_id=?",
                       number[0]["quantity"] + shares, symbol, session["user_id"])
        else:
            db.execute("INSERT INTO owned (user_id, stock, quantity) VALUES (?)",
                       [session["user_id"], symbol, shares])

        # Subtract stock price from user's cash
        db.execute("UPDATE users SET cash=? WHERE id=?",
                   cash - value, session["user_id"])

        # Log transaction
        db.execute("INSERT INTO transactions (user_id, stock, quantity, action, total) VALUES (?)", [
                   session["user_id"], symbol, shares, "BUY", value])

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Query database for transactions
    transactions = db.execute(
        "SELECT date, stock, quantity, action, total FROM transactions WHERE user_id=?", session["user_id"])

    # Render transactions
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get(
                "username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)

        # Query database for symbol
        values = lookup(request.form.get("symbol"))

        # Ensure stock exists
        if not values:
            return apology("invalid symbol", 400)

        # Unpack lookup values
        value, symbol = values.values()

        # Render stock and price
        return render_template("quoted.html", symbol=symbol, value=value)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
# -> tuple[Any, Literal[403]] | Any:# -> tuple[Any, Literal[403]] | Any:
def register():
    """Register user"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get(
                "username")
        )

        # Ensure username doesn't exist
        if len(rows) != 0:
            return apology("user already exists", 400)

        # Ensure passwords match
        if request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords don't match", 400)

        # Add user to database
        hash = generate_password_hash(request.form.get("password"))
        db.execute("INSERT INTO users (username, hash) VALUES (?)",
                   [request.form.get("username"), hash])

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        shares = request.form.get("shares")
        symbol = request.form.get("symbol")

        # Ensure symbol was submitted
        if not symbol:
            return apology("must provide symbol", 403)

        # Ensure number of shares was submitted
        elif not shares:
            return apology("must provide number of shares", 403)

        shares = shares.strip()
        symbol = symbol.strip()

        # Ensure number of shares is a positive integer
        if not shares.isdecimal() or int(shares) < 1 or int(shares) != float(shares):
            return apology("invalid number of shares", 400)
        shares = int(shares)

        # Query database for symbol
        values = lookup(symbol)

        # Ensure stock exists and owned by user
        quantity = db.execute(
            "SELECT quantity FROM owned WHERE stock=? AND user_id=?", symbol, session["user_id"])
        if not values or not quantity:
            return apology("invalid symbol", 400)
        quantity = quantity[0]["quantity"]

        # Ensure user isn't selling more shares than they own
        if shares > quantity:
            return apology("invalid amount", 400)

        # Get total stock price
        value = values["price"] * shares

        # Decrement number of shares and delete null stocks
        db.execute("UPDATE owned SET quantity=? WHERE stock=? AND user_id=?",
                   quantity - shares, symbol, session["user_id"])
        db.execute("DELETE FROM owned WHERE quantity<1")

        # Add stock price to user's cash
        cash = db.execute("SELECT cash FROM users WHERE id=?",
                          session["user_id"])[0]["cash"]
        db.execute("UPDATE users SET cash=? WHERE id=?",
                   cash + value, session["user_id"])

        # Log transaction
        db.execute("INSERT INTO transactions (user_id, stock, quantity, action, total) VALUES (?)", [
                   session["user_id"], symbol, shares, "SELL", value])

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        stocks = db.execute(
            "SELECT stock FROM owned WHERE user_id=?", session["user_id"])
        return render_template("sell.html", stocks=stocks)
