m, s, c = map(int, input().split())
a = sorted([int(input()) for i in range(c)])
b = sorted([a[i] - a[i - 1] - 1 for i in range(1, c)], reverse=True)
print(a[-1] - a[0] + 1 - sum(b[:m - 1]))
