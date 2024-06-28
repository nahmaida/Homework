def pythagorean_triplets():
    for b in range(1,1000):
        for a in range(1,b):
            c = (a ** 2 + b ** 2) ** 0.5
            if a + b + c == 1000:
                return a,b,c
    return 0,0,0

def main():
    a, b, c = pythagorean_triplets()
    print(f"{a} {b} {c}")


if __name__ == "__main__":
    main()
