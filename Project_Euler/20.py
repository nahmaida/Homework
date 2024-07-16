def factorial(n: int) -> int:
    if n < 2:
        return n
    else:
        return n * factorial(n - 1)


def digit_sum(n: int) -> int:
    if n < 10:
        return n
    else:
        return n % 10 + digit_sum(n // 10)


def main() -> None:
    print(digit_sum(factorial(100)))


if __name__ == "__main__":
    main()
