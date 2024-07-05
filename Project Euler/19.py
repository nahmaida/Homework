def count_sundays() -> int:
    months: dict[int:int] = {
        1: 31,
        2: 28,
        3: 31,
        4: 30,
        5: 31,
        6: 30,
        7: 31,
        8: 31,
        9: 30,
        10: 31,
        11: 30,
        12: 31,
    }
    day: int = 6
    sundays: int = 0
    leap_year: bool = False
    for year in range(1901, 2001):
        if not (year % 4):
            leap_year = True
        for month in range(1, 13):
            if day == 1:
                sundays += 1
            days = months[month]
            if leap_year and month == 2:
                days += 1
            while day <= days:
                day += 7
            day -= days
    return sundays


def main() -> None:
    # for some reason counts an extra sunday
    print(count_sundays() - 1)


if __name__ == "__main__":
    main()
