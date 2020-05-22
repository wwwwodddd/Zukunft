a, b, c, x, y = map(int, raw_input().split())
print min(a * x + b * y, 2 * c * x + abs(y - x) * b, 2 * c * y + abs(x - y) * a, 2 * c * max(x, y))