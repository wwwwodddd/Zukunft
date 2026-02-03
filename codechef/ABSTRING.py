import collections
for t in range(int(input())):
	n = int(input())
	s = input()
	c = collections.Counter(s)
	if sum(c[i] % 2 for i in c):
		print('NO')
	else:
		print('YES')