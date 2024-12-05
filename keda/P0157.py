n, x, y = map(int, input().split())
print(max(n - (y + x - 1) // x, 0))