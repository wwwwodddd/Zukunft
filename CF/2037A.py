import collections
for t in range(int(input())):
	input()
	c = collections.Counter(map(int, input().split()))
	print(sum(c[i] // 2 for i in c))