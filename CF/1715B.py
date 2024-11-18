import math
for t in range(int(input())):
	n, k, b, s = map(int, input().split())
	s -= k * b
	if 0 <= s <= n * (k - 1):
		a = [s // n + 1] * (s % n) + [s // n] * (n - s % n)
		a[0] += k * b
		print(*a)
	else:
		print(-1)