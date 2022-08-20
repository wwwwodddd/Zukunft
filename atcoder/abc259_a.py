n, m, x, t, d = map(int, input().split())
print(t - max(x - m, 0) * d)