for t in range(int(input())):
	x, y = map(int, input().split())
	if x > y:
		x, y = y, x
	z = y
	if x == 0 and y > 0:
		print(-1)
		continue
	while x < y:
		z += 1
		x *= 2
	print(z)