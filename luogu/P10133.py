n = int(input())
a = list(map(int, input().split()))
for i in range(1, n)[::-1]:
	a[i] -= a[i - 1]
for i in range(1, n)[::-1]:
	a[i] -= a[i - 1]
s = 0
for i in range(n):
	s += abs(a[i])
print(s)
