for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	o = []
	e = []
	for i in range(2 * n):
		if a[i] & 1:
			o.append(i + 1)
		else:
			e.append(i + 1)
	if len(o) & 1:
		o.pop()
	o += e
	for i in range(0, 2 * n - 2, 2):
		print(o[i], o[i + 1])
