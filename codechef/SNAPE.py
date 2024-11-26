for t in range(int(input())):
	b, l = map(int, input().split())
	print((l * l - b * b) ** 0.5, (l * l + b * b) ** 0.5)