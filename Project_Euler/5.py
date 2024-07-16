def smallest_multiple():
    i = 20
    while True:
        if not [i / j for j in range(1, 21)]:
            return i


def main():
    print(smallest_multiple())


if __name__ == "__main__":
    main()
