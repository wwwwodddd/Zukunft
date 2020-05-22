n, k = map(int, raw_input().split())
z = (n / k) ** 3
if k % 2 == 0:
	z += ((n + k / 2) / k) ** 3
print z
