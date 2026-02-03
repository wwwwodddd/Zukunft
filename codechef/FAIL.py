for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	s = 0
	for i in range(len(a)):
		s += a[i]
		if s < 40 * (i + 1):
			print('No')
			break
	else:
		print('Yes')
