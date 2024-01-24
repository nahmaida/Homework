"""Зачетное."""


def len_checker() -> None:
    """Проверяет, является ли число трехзначным."""
    number: str = input("Введите число: ")
    positive_range = [str(i) for i in range(100, 1000)]
    negative_range = [str(i) for i in range(-999, -99)]
    if number not in positive_range and number not in negative_range:
        print("Error")


def num_halver(number: float) -> float:
    """Делит число на 2, если оно от 30 до 80.

    Параметры:
        number (float): Число

    Возвращает:
        float: Поделенное на 2 число, или просто число
    """
    if 30 <= number <= 80:
        number = number / 2
    return number


def multiples_of_5() -> None:
    """Выводит двухзначные числа, кратные 5."""
    for i in range(10, 101):
        if not i % 5:
            print(i)


def dragon_heads(age: int) -> int:
    """Вычисляет, сколько у дракона будет голов.

    Параметры:
        age (int): Возраст дракона

    Возвращает:
        int: Количество голов
    """
    if age < 50:
        return 3 * age
    return 150 + 2 * (age - 50)


def input_max(length: int) -> float:
    """Выводит максимальное из введенных чисел заданого количества.

    Параметры:
        length (int): Количество вводимых чисел

    Возвращает:
        float: Наибольшнн число
    """
    numbers: list[float] = []
    i: int = 0
    while i < length:
        try:
            number: float = float(input("Число: "))
        except ValueError:
            print("Неверный ввод.")
            continue
        numbers.append(number)
        i += 1
    return max(numbers)


def main() -> None:
    """Основная функция."""
    print(
        "1. Задание 1 (базовый).\n",
        "2. Задание 2 (базовый).\n",
        "\n3. Задание 1 (веселее).\n",
        "4. Задание 2 (веселее).\n",
        "5. Задание 3 (веселее).\n",
    )
    mode: str = input(">>> ")
    match mode:
        case "1":
            len_checker()
        case "2":
            number: float = float(input("Число: "))
            print(num_halver(number))
        case "3":
            multiples_of_5()
        case "4":
            age: int = int(input("Возраст: "))
            print(dragon_heads(age))
        case "5":
            length: int = int(input("Количество чисел: "))
            print(input_max(length))
        case _:
            print("Неверный ввод.")


if __name__ == "__main__":
    main()
