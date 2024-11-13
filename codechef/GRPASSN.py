import collections
for t in range(int(input())):
	n = int(input())
	a = collections.Counter(map(int, input().split()))
	for i in a:
		if a[i] % i != 0:
			print('NO')
			break
	else:
		print('YES')
