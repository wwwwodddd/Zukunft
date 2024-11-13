for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	while a[-1] == 0:
		a.pop()
	print(len(a) - 1)
