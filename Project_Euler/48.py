def main() -> None:
    sum: int = 0
    for i in range(1, 1001):
        sum += (i ** i)
    print(sum % (10 ** 10))


if __name__ == "__main__":
    main()
