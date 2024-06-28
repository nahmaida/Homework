def sum_of_squares(n):
    return sum([i ** 2 for i in range(1, n+1)])


def square_of_sum(n):
    return sum(range(1, n + 1)) ** 2


def main():
    num = 100
    val = square_of_sum(num) - sum_of_squares(num)
    print(val)


if __name__ == "__main__":
    main()
