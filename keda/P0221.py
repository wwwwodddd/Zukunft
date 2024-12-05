import collections
n = int(input())
a = list(map(int, input().split()))
c = collections.Counter(a)
for i in range(max(a) + 1):
	print(c[i])