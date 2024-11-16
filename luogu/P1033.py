h, s1, v, l, k, n = map(float, input().split())
i = min(int(s1 - v * ((h - k) / 5) ** 0.5 + l), int(n))
j = max(int(s1 - v * (h / 5) ** 0.5), 0)
print(i - j)
