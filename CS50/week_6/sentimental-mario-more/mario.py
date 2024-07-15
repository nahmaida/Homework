def print_pyramid(size: int) -> None:
    for i in range(1, size + 1):
        val: str = "#" * i
        print(f"{val:>{size}}  {val}")


def main() -> None:
    while True:
        height: str = input("Height: ")
        if height.isdigit() and 9 > int(height) > 0:
            size: int = int(height)
            break
    print_pyramid(size)


if __name__ == "__main__":
    main()
