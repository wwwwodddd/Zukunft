def S(a, x):
	if x == 0:
		return 0
	if x & 1:
		return (S(a, x - 1) * a + 1) % m
	else:
		return S(a * a % m, x // 2) * (a + 1) % m
a, x, m = map(int, input().split())
print(S(a, x))