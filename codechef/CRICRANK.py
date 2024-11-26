for t in range(int(input())):
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	if sum(a[i] > b[i] for i in range(3)) >= 2:
		print('A')
	else:
		print('B')