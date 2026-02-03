import collections
for t in range(int(input())):
	input()
	c = collections.Counter(input())
	if sum(c[i] % 2 for i in c):
		print('NO')
	else:
		print('YES')
