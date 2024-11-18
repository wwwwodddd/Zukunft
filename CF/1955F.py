for t in range(int(input())):
	a, b, c, d = map(int, input().split())
	print(a // 2 + b // 2 + c // 2 + d // 2 + (a % 2 == b % 2 == c % 2 == 1))