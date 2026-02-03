for t in range(int(input())):
	n, k = map(int, input().split())
	if n % k == 0:
		print(0)
	else:
		print(1)
