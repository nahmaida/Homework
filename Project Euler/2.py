def fibo(n: int) -> int:
    if n < 2:
        return n
    return fibo(n - 1) + fibo(n - 2)


def main() -> None:
    sum: int = 0
    i: int = 3
    while True:
        value = fibo(i)
        if value > 4_000_000:
            break
        sum += value
        i += 3
    print(sum)


if __name__ == "__main__":
    main()
