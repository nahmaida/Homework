from itertools import permutations


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    for i in range(2, n):
        if not n % i:
            return False
    return True


def is_circular(n: int) -> bool:
    for perm in permutations(str(n)):
        if not is_prime(int("".join(perm))):
            return False
    return True


# for SOME FCKING REASON this shit makes
# my laptop randomly turn off. Gives correct result
# for i < 100, so i assume it is correct
# Also, it somehow removed dash to dock
def main() -> None:
    count: int = 0
    for i in range(10**6):
        print(i)
        count += is_circular(i)
    print(count)


if __name__ == "__main__":
    main()
