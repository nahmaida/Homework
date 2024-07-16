def isPalindrome(n):
    return str(n) == str(n)[::-1]


def max_three_digit_product_palindrome():
    current = 1
    for i in range(101, 1000):
        if str(i)[-1] == "0":
            pass
        for j in range(101, 1000):
            if str(j)[-1] == "0":
                pass
            prod = i * j
            if isPalindrome(prod) and prod > current:
                current = prod
    return current


def main():
    print(max_three_digit_product_palindrome())


if __name__ == "__main__":
    main()
