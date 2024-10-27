n, k = map(int, input().split())
z = -1e18
for i in range(n):
	f, t = map(int, input().split())
	if t <= k:
		z = max(z, f)
	else:
		z = max(z, f - t + k)
print(z)