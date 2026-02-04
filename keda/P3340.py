n, l, r = map(int, input().split())
z = 0
for i in range(60):
	if n >> i & 1:
		z += max(min(r, 2 ** (i + 1) - 1) - max(l, 2 ** i) + 1, 0)
print(z)