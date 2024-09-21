a = []
n = int(input())
for i in range(n):
	c, r, s, d = input().split()
	a.append((-2 * int(r) - 3 * int(s) - int(d), c))
a.sort()
for i in range(min(len(a), 2)):
	print(a[i][1])