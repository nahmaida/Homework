def main() -> None:
    mults_of_3_5: list = [i for i in range(1000) if (not i % 3) or (not i % 5)]
    print(sum(mults_of_3_5))


if __name__ == "__main__":
    main()
