"""Задания из отдельных файлов."""
import conditionals
import final
import loops


def main() -> None:
    """Основная функция."""
    print("1. Задания с if.\n", "2. Задания с циклами.\n", "3. Зачетное.\n")
    mode: str = input(">>> ")
    match mode:
        case "1":
            conditionals.main()
        case "2":
            loops.main()
        case "3":
            final.main()
        case _:
            print("Неверный ввод.")


if __name__ == "__main__":
    main()