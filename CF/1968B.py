for t in range(int(input())):
	n, m = map(int, input().split())
	a = input()
	b = input()
	i = 0
	for c in b:
		if i < len(a) and a[i] == c:
			i += 1
	print(i)