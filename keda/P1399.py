n = int(input())
a = [0] + list(map(int, input().split()))
for i in range(n):
	a[i + 1] += a[i]
m = int(input())
for i in range(m):
	l, r = map(int, input().split())
	print(a[r] - a[l - 1])