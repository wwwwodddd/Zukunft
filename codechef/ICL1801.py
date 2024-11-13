for t in range(int(input())):
	n, m = map(int, input().split())
	a = []
	for i in range(n):
		a += list(map(int, input().split()))
	a.sort(reverse=True)
	if sum(a[::2]) > sum(a[1::2]):
		print('Cyborg')
	elif sum(a[::2]) < sum(a[1::2]):
		print('Geno')
	else:
		print('Draw')
