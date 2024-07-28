from string import digits
from itertools import permutations

j: int = 0
for i in permutations(digits):
    j += 1
    if j == 1000000:
        print(i)