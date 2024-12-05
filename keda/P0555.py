r, m, y = map(int, input().split())
print(int(m * (1 + r / 100) ** y))