for t in range(int(input())):
	m, p = map(int, input().split())
	print(min((1000 - p - m) // 21, 299 - m))
