n = int(input())
a = list(map(int, input().split()))
z = 0
for i in range(1, n + 1):
	z += i // 2 * (n - i + 1)
c = [0 for i in range(n + 1)]
if n % 2 == 0:
	c[a[n // 2]] = 1
for i in range((n + 1) // 2)[::-1]:
	z -= c[a[i]] * (i + 1)
	c[a[i]] += 1
	if i > 0:
		c[a[n - i]] += 1
c = [0 for i in range(n + 1)]
if n % 2 == 1:
	c[a[n // 2]] = 1
for j in range((n + 1) // 2, n):
	z -= c[a[j]] * (n - j)
	c[a[j]] += 1
	c[a[n - j - 1]] += 1
print(z)