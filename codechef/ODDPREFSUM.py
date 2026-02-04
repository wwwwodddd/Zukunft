for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(n):
		a[i] %= 2
	if sum(a) == 1:
		print('Yes')
	else:
		print('No')