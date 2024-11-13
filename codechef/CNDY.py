for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	for i in range(2, 2 * n):
		if a[i - 2] == a[i]:
			print('No')
			break
	else:
		print('Yes')
