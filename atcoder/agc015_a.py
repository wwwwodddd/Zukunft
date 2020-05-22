n, a, b = map(int, raw_input().split())
print max((n - 2) * (b - a) + 1, 0)