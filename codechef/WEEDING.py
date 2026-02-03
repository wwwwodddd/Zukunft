for t in range(int(input())):
	n, m, k = map(int, input().split())
	a = list(map(int, input().split()))
	if m - a[-1] + 1 >= k:
		print('Yes')
	else:
		print('No')
