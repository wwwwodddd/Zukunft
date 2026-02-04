n = int(input())
a = list(map(int, input().split()))
z = 0
s = a[0]
for i in range(1, n):
	s += a[i]
	z += max(s, 0)
print(z)
