for t in range(int(input())):
	s, x, y, z = map(int, input().split())
	if x + y + z <= s:
		print(0)
	elif min(x, y) + z <= s:
		print(1)
	else:
		print(2)
