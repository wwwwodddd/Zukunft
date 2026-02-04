import collections
for t in range(int(input())):
	n, k = map(int, input().split())
	c = collections.Counter(input())
	s = sum(c[i] % 2 for i in c)
	if s <= k + 1:
		print('YES')
	else:
		print('NO')
