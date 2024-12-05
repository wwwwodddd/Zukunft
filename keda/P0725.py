import bisect
n = int(input())
a = list(map(int, input().split()))
t = int(input())
i = bisect.bisect_left(a, t)
if i < len(a) and a[i] == t:
	print(i)
else:
	print(-1)
