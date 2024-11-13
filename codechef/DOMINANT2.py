import collections
for t in range(int(input())):
	n = int(input())
	a = collections.Counter(map(int, input().split()))
	a[0] = 0
	b = a.most_common(2)
	print(['NO', 'YES'][b[0][1] > b[1][1]])