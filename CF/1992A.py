for t in range(int(input())):
	a = sorted(map(int, input().split()))
	for i in range(5):
		a.sort()
		a[0] += 1
	print(a[0] * a[1] * a[2])