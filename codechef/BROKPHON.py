for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	v = [0 for i in a]
	for i in range(1, len(a)):
		if a[i - 1] != a[i]:
			v[i - 1] = v[i] = 1
	print(sum(v))
