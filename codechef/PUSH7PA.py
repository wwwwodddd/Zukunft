from collections import Counter
for t in range(int(input())):
	n = int(input())
	c = Counter(map(int, input().split()))
	print(max(x + c[x] - 1 for x in c))