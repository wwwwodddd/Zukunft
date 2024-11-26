import collections
for t in range(int(input())):
	n = int(input())
	a = collections.Counter(map(int, input().split()))
	print(['No', 'Yes'][n >= a.most_common(1)[0][1] * 2 - 1])
