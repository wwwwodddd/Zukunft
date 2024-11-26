for t in range(int(input())):
	n, m = map(int, input().split())
	print(['YES', 'NO'][(n - m) % 2])
