n = int(input())
a = list(map(int, input().split()))
for i in range(n):
	mn = 1e10
	if i > 0:
		mn = min(mn, a[i] - a[i - 1])
	if i + 1 < n:
		mn = min(mn, a[i + 1] - a[i])
	print(mn, max(a[i] - a[0], a[-1] - a[i]))