import bisect
n = int(input())
a = list(map(int, input().split()))
for i in range(1, n):
	a[i] += a[i - 1]
input()
for x in map(int, input().split()):
	print(bisect.bisect_left(a, x) + 1)