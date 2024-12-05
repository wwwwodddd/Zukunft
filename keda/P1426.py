n, m = map(int, input().split())
n |= 1
print(*range(n, m + 1, 2))