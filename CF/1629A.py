for t in range(int(input())):
	n, k = map(int, input().split())
	a = sorted(zip(map(int, input().split()), map(int, input().split())))
	for x, y in a:
		if k >= x:
			k += y
	print(k)