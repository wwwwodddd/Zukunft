n, m = map(int, input().split())
s = set(range(1, m + 1))
for i in range(n):
	x, y = map(int, input().split())
	s -= set(range(x, y + 1))
print(len(s))
print(*sorted(s))