for t in range(int(input())):
	r, g, b = map(int, input().split())
	print(min(r, g, b) + (r + g + b) * 3)