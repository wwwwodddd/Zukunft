import bisect
n, m = map(int, input().split())
a = sorted(map(int, input().split()))
for i in map(int, input().split()):
	print(bisect.bisect(a, i), end=' ')