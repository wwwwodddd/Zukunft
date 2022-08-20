import itertools
n, m = map(int, input().split())
for i in itertools.combinations(range(1, m + 1), n):
	print(*i)