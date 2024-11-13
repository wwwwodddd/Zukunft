for t in range(int(input())):
	input()
	a = sorted(map(int, input().split()))
	print(sum(a) * 2 - a[0] - a[1])
