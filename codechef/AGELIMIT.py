for t in range(int(input())):
	x, y, a = map(int, input().split())
	print(['NO','YES'][x<=a<y])