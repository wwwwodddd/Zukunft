for t in range(int(input())):
	r, g, b = map(int, input().split())
	print(['NO', 'YES'][max(r, g, b) * 2 <= r + g + b])