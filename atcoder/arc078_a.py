n = int(input())
a = list(map(int, input().split()))
s = sum(a)
t = 0
z = 1e18
for i in range(n - 1):
	t += a[i]
	s -= a[i]
	z = min(z, abs(s - t))
print(z)