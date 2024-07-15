def readability(text: str) -> int:
    sentences: int = 1 + sum([text.count(symb + " ") for symb in ".!?"])
    words: int = len(text.split())
    letters: int = len([char for char in text if char.isalpha()])
    L: float = letters / (words / 100.0)
    S: float = sentences / (words / 100.0)
    return round(0.0588 * L - 0.296 * S - 15.8)


def main() -> None:
    text: str = input("Text: ")
    grade: int = readability(text)
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


if __name__ == "__main__":
    main()
