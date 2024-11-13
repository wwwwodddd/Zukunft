import collections
for t in range(int(input())):
	n = int(input())
	c = collections.Counter(map(int, input().split()))
	print(*c.most_common(1)[0])