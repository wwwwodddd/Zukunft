import collections
for t in range(int(input())):
	n = int(input())
	print(n - collections.Counter(input().split()).most_common(1)[0][1])