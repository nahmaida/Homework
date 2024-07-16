def is_prime(n: int) -> bool:
    return 0 not in [n % i for i in range(2, n)]


def get_biggest_prime_factor(n: int) -> int:
    if is_prime(n):
        return None
    current: int = 1
    while not n % 2:
                n /= 2
                current = 2
    for i in range(3, round(n**0.5) + 1, 2):
        if is_prime(i):
            while not n % i:
                n /= i
                current = i
    if n > 2:
        current = n
    return current


def main():
    num = 600851475143
    print(get_biggest_prime_factor(num))


if __name__ == "__main__":
    main()
