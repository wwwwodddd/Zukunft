import collections
for t in range(int(input())):
	n = int(input())
	a = collections.Counter((int(i) // 2 for i in input().split()))
	print(n - a.most_common(1)[0][1])
