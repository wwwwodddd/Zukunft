for t in range(int(input())):
	n, m = map(int, input().split())
	a = sorted(map(int, input().split()))
	b = sorted(map(int, input().split()))
	z = 0
	j = 0
	for i in a:
		while j < m and b[j] < i:
			j += 1
		z += j
	print(z)