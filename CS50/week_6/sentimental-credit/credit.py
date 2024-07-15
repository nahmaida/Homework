def validate(number: str) -> bool:
    total: int = 0
    mode: int = 0
    for char in number[::-1]:
        if mode == 0:
            total += int(char)
            mode = 1
        else:
            total += sum([int(digit) for digit in str(int(char) * 2)])
            mode = 0
    return not total % 10


def check_card(number: str) -> str:
    size: int = len(number)

    if not validate(number):
        return "INVALID"

    elif size == 15 and number[:2] in ["34", "37"]:
        return "AMEX"

    elif size == 16 and int(number[:2]) in range(50, 56):
        return "MASTERCARD"

    elif size in [13, 16] and number[0] == "4":
        return "VISA"

    return "INVALID"


def main() -> None:
    while True:
        number: str = input("Number: ")
        if number.isdigit():
            break
    print(check_card(number))


if __name__ == "__main__":
    main()
