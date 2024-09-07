for t in range(int(input())):
	a = input().split()
	for i in range(len(a)):
		if len(a[i]) == 4:
			a[i] = '****'
	print(' '.join(a))