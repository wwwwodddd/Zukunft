for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	for i in range(len(a)):
		if a[i] > b[i]:
			a[i], b[i] = b[i], a[i]
	print(max(a) * max(b))