import bisect
n = int(input())
a = sorted(map(int, input().split()))
for i in range(int(input())):
	x = int(input())
	print(bisect.bisect_right(a, x))