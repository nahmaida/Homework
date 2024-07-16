def div_tri_numbers(n):
    num = 0
    nat_num = 1
    while True:
        num += nat_num
        nat_num += 1
        n_divs = 2
        for i in range(2, num):
            if not num % i:
                n_divs += 1
            if n_divs == n:
                return num


def main():
    num = 500
    print(div_tri_numbers(num))


if __name__ == "__main__":
    main()
