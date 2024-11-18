n, k = map(int, input().split())
i = 1
a = []
while i * i < n:
	if n % i == 0:
		a.append(i)
		a.append(n // i)
	i += 1
if i * i == n:
	a.append(i)
a.sort()
if k > len(a):
	print(-1)
else:
	print(a[k - 1])
