import string


def alphabet(s: str) -> int:
    return string.ascii_uppercase.index(s) + 1


def main():
    sum = 0

    with open("0022_names.txt") as names:
        names = names.read()
        names_list: list[str] = sorted(names.replace(",", " ").replace('"', "").split())

    for name in names_list:
        value: int = 0

        for char in name:
            value += alphabet(char)

        value *= names_list.index(name) + 1
        sum += value

    print(sum)


if __name__ == "__main__":
    main()
