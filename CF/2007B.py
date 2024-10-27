for t in range(int(input())):
	n, m = map(int, input().split())
	x = max(map(int, input().split()))
	for i in range(m):
		o, l, r = input().split()
		if int(l) <= x <= int(r):
			if o == '+':
				x += 1
			else:
				x -= 1
		print(x, end=' ')
	print()