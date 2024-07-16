def div_sum(n: int) -> int:
    sum: int = 1
    for i in range(2, n):
        if not n % i:
            sum += i
    return sum


def check_amicable(n: int) -> bool:
    sum: int = div_sum(n)
    return n != sum and div_sum(sum) == n


def main() -> None:
    sum = 0
    for i in range(10001):
        if check_amicable(i):
            sum += i
    print(sum)


if __name__ == "__main__":
    main()
