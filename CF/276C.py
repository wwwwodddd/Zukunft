n, q = map(int, input().split())
a = sorted(map(int, input().split()), reverse=True)
s = [0 for i in range(n + 1)]
for i in range(q):
	x, y = map(int, input().split())
	s[x - 1] += 1
	s[y] -= 1
for i in range(n):
	s[i + 1] += s[i]
s.sort(reverse=True)
z = 0
for i in range(n):
	z += a[i] * s[i]
print(z)