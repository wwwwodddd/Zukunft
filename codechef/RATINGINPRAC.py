for t in range(int(input())):
	n = input()
	a = list(map(int, input().split()))
	print(['No', 'Yes'][a == sorted(a)])
