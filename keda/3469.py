import math
n, m = map(int, input().split())
print(math.comb(n + m - 2, n - 1))