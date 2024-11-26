for t in range(int(input())):
	a = list(map(int, input().split()))
	s = sum(a[::2]) - sum(a[1::2])
	if s == 0:
		print(0)
	elif s > 0:
		print(1)
	else:
		print(2)
