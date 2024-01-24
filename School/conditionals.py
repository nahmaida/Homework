def num_tweaker() -> None:
    """
    Запрашивает число.
    Прибавляет 1, если больше 0; Заменяет на 10, если равно 0; отнимает 2, если меньше 0.
    """
    while True:
        try:
            number: int = int(input("Введите число: "))
            break
        except ValueError:
            print("Неверный ввод.")
            continue
    if number > 0:
        number += 1
    elif number == 0:
        number = 10
    else:
        number -= 2
    print(number)


def var_tweaker(a: int, b: int) -> None:
    """
    Если a равно b, а и b заменяются на их сумму.
    Иначе, а и b заменяются на ноль.

    Парамтеры:
        a (int): Первое число
        b (int): Второе число
    """
    match a == b:
        case True:
            a = b = a + b
        case False:
            a = b = 0
    print(f"a: {a}, b: {b}")


def quadratic_equation(a: float, b: float, c: float) -> tuple:
    """Вычисляет корни квадратного уравнения.

    Парамтеры:
    a (float): Коэффициент a
    b (float): Коэффициент b
    c (float): Свободный член

    Возвращает:
    tuple: Корни уравнения
    """
    d = (b**2) - (4 * a * c)
    x1 = (-b - d**0.5) / (2 * a)
    x2 = (-b + d**0.5) / (2 * a)
    return x1, x2


def get_quadrant() -> None:
    """Запрашивает координаты точки, выводит её четверть."""
    while True:
        try:
            x: float = float(input("Введите x: "))
            y: float = float(input("Введите y: "))
            break
        except ValueError:
            print("Неверный ввод.")
            continue
    pos = (x >= 0, y >= 0)
    match pos:
        case (True, True):
            print("1")
        case (False, True):
            print("2")
        case (False, False):
            print("3")
        case (True, False):
            print("4")


def num_to_word(num: int) -> str:
    """Переводит число от 0 до 9 в слово.

    Парамтеры:
    num (int): Число от 0 до 9

    Возвращает:
    str: Слово, соответствующее числу
    """
    words = (
        "ноль",
        "один",
        "два",
        "три",
        "четыре",
        "пять",
        "шесть",
        "семь",
        "восемь",
        "девять",
    )
    return words[num] if 0 <= num < 10 else "Неверный ввод."


def points_distance() -> None:
    """
    Запрашивает координаты точек.
    Выводит точку с наименьшим расстоянием до a и само расстояние.
    """
    while True:
        try:
            a: float = float(input("A: "))
            b: float = float(input("B: "))
            c: float = float(input("C: "))
            break
        except ValueError:
            print("Неверный ввод.")
            continue
    b_distance = abs(b - a)
    c_distance = abs(c - a)
    if b_distance > c_distance:
        print(f"C; {c_distance}")
    else:
        print(f"B; {b_distance}")


def main() -> None:
    """Основная функция."""
    print(
        "1. Задание 1, 2, 3.\n",
        "2. Задание 4.\n",
        "3. Задание 6 (задания 5 нет).\n",
        "4. Задание 7.\n",
        "5. Задание 8.\n",
        "6. Задание 9.\n",
    )
    mode: str = input(">>> ")
    match mode:
        case "1":
            num_tweaker()
        case "2":
            a = int(input("a: "))
            b = int(input("b: "))
            var_tweaker(a, b)
        case "3":
            a = int(input("a: "))
            b = int(input("b: "))
            c = int(input("c: "))
            x1, x2 = quadratic_equation(a, b, c)
            print(f"x1: {x1}, x2: {x2}")
        case "4":
            get_quadrant()
        case "5":
            a = int(input("a: "))
            print(num_to_word(a))
        case "6":
            points_distance()
        case _:
            print("Неверный ввод.")


if __name__ == "__main__":
    main()
