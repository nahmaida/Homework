def main() -> None:
    sum: int = 0
    for i in range(10**6):
        binary: str = bin(i)[2:]
        if str(i) != str(i)[::-1] or binary != binary[::-1]:
            continue
        print(f"Num: {i} Bin: {binary}")
        sum += i
    print(sum)


if __name__ == "__main__":
    main()
