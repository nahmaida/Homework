n = int(input())
count: int = 0
while n > 0:
    count += 1
    if count % 2 and count % 3:
        n -= 1
print(count)
