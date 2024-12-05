n = int(input())
a = [0] + list(map(int, input().split()))
for i in range(n):
	a[i + 1] += a[i]
m = int(input())
for i in range(m):
	x, y = map(int, input().split())
	print(a[y] - a[x - 1])