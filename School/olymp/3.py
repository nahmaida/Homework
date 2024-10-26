n = int(input())
arr: list[int] = [0]
for _ in range(n):
    arr.append(int(input()))

ans: int = 1
best_count: int = arr[1]
if n > 1:
    best_count += arr[2] * 2
if n > 2:
    best_count += arr[3]

i: int = 2
count: int = 1

while count < n:
    if i <= n:
        temp = arr[i]
    
    if i * 2 + 1 <= n:
        temp += 2 * arr[i * 2] + arr[i * 2 + 1] + arr[i * 2 - 1]
    elif i * 2 <= n:
        temp += 2 * arr[i * 2] + arr[i * 2 - 1]
    elif i * 2 - 1 <= n:
        temp += 2 * arr[i * 2 - 1]

    if temp > best_count:
        best_count = temp
        ans = i

    i += 1 + n
    i %= n
    count += 1

print(f"{count}\n{ans}")