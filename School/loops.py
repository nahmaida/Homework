def range_print(begin: int, end: int) -> None:
    """
    Выводит числа в диапазоне от begin до end.

    Параметры:
        begin (int): Начало диапазона
        end (int): Конец диапазона
    """
    for i in range(begin, end + 1):
        print(i)


def multiplication_table(number: float) -> None:
    """
    Выводит таблицу умножения для числа number.

    Параметры:
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
    for i in range(1, n + 1):
        print(f"{a}^{i} = {a ** i}")


def sum_multiples_of_3(x: int, y: int) -> int:
    """Вычисляет сумму чисел, кратных 3, в диапазоне от x до y.

    Параметры:
        x (int): Начало диапазона
        y (int): Конец диапазона

    Возвращает:
        int: Сумма чисел, кратных 3, в диапазоне от x до y
    """
    multiples: list[int] = [i for i in range(x, y + 1) if not i % 3]
    return sum(multiples)


def get_names() -> list[str]:
    """Запрашивает имена покупателей и возвращает их в виде списка.

    Возвращает:
        list[str]: Список введенных имен
    """
    name: str = str()
    names: list[str] = []
    while name != "0":
        name = input("Имя (0 - выход): ")
        names.append(name)
    del names[-1]
    return names


def validate_pin() -> None:
    """Проверяет, равен ли пин-код 1234."""
    pin: str = input("Пин-код: ")
    while pin != "1234":
        print("Неверный пин-код.")
        pin = input("Пин-код: ")
    print("Все верно!")


def smallest_square(n: int) -> int:
    """Находит наименьшее число, квадрат которого больше n.

    Параметры:
        n (int): Число

    Возвращает:
        int: Наименьшее число, квадрат которого больше n
    """
    num: int = 1
    # удобнее было бы использовать for i in range
    while num**2 <= n:
        num += 1
    return num


def print_triangle() -> None:
    """Выводит треугольник введенной высоты."""
    while True:
        try:
            n: int = int(input("Высота: "))
            break
        except ValueError:
            print("Неверный ввод.")
            continue
    spaces = n - 1
    i = 0
    # опять же, удобнее for i in range
    while i < n:
        for _ in range(0, spaces):
            print(end=" ")
        spaces -= 1
        for _ in range(0, i+1):
            print("^ ", end="")
        print("\n")
        i += 1


def main() -> None:
    """Основная функция."""
    print(
        "1. Задание 1 (for).\n",
        "2. Задание 2 (for).\n",
        "3. Задание 3 (for).\n",
        "4. Задание 4 (for).\n",
        "\n5. Задание 1 (while).\n",
        "6. Задание 2 (while).\n",
        "7. Задание 3 (while).\n",
        "8. Задание 4 (while).\n",
    )
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
        case "4":
            x: int = int(input("От: "))
            y: int = int(input("До: "))
            print(sum_multiples_of_3(x, y))
        case "5":
            names: list[str] = get_names()
            print(names)
        case "6":
            validate_pin()
        case "7":
            n: int = int(input("Число: "))
            print(smallest_square(n))
        case "8":
            print_triangle()
        case _:
            print("Неверный ввод.")


if __name__ == "__main__":
    main()
