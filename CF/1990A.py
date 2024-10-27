import collections
for t in range(int(input())):
	n = int(input())
	c = collections.Counter(map(int, input().split()))
	for i in c:
		if c[i] & 1:
			print('YES')
			break
	else:
		print('NO')