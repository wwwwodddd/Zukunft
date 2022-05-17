n, a, x, y = map(int, input().split())
print(min(n * x, a * x + (n - a) * y))