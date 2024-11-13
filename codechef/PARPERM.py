import bisect
n = 100000
p = [0 for i in range(n + 1)]
for i in range(2, n + 1):
	if p[i] == 0:
		for j in range(i + i, n + 1, i):
			p[j] = i
for t in range(int(input())):
	n, k = map(int, input().split())
	a = [1]
	b = []
	for i in range(2, n + 1):
		if i * 2 > n and p[i] == 0:
			a.append(i)
		else:
			b.append(i)
	if k <= len(a):
		print('Yes')
		print(*a[:k])
	elif k >= len(b):
		print('Yes')
		print(*b, *a[:k - len(b)])
	else:
		print('No')
