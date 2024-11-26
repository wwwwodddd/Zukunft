while True:
	n = int(input())
	if n == 0:
		break
	a = [0] + list(map(int, input().split()))
	for i in range(1, n + 1):
		if a[a[i]] != i:
			print('not ambiguous')
			break
	else:
		print('ambiguous')