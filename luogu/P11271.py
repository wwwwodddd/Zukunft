x, y, p, q = map(int, input().split())
print(min(p, q, x - p, y - q))