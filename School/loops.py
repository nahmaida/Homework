def range_print(begin: int, end: int) -> None:
    """
    Выводит числа в диапазоне от begin до end.

    Парамтеры:
        begin (int): Начало диапазона
        end (int): Конец диапазона
    """
    for i in range(begin, end + 1):
        print(i)


def multiplication_table(number: float) -> None:
    """
    Выводит таблицу умножения для числа number.

    Парамтеры:
        number (float): Число
    """
    for i in range(1, 11):
        print(f"{number} * {i} = {number * i}")


def powers() -> None:
    """Выводит число a в степенях от 1 до n."""
    while True:
        try:
            a: int = int(input("Введите число: "))
            n: int = int(input("Введите число степеней: "))
            break
        except ValueError:
            print("Неверный ввод.")
            continue
    for i in range(1, n+1):
        print(f"{a}^{i} = {a ** i}")


def main() -> None:
    """Основная функция."""
    print("1. Задание 1.\n", "2. Задание 2.\n", "3. Задание 3.\n")
    mode: str = input(">>> ")
    match mode:
        case "1":
            begin: int = int(input("От: "))
            end: int = int(input("До: "))
            range_print(begin, end)
        case "2":
            number: float = float(input("Число: "))
            multiplication_table(number)
        case "3":
            powers()
        case _:
            print("Неверный ввод.")


if __name__ == "__main__":
    main()
