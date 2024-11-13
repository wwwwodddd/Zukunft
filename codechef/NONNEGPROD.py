for t in range(int(input())):
	n = int(input())
	x = 0
	y = 0
	for i in map(int, input().split()):
		if i < 0:
			x += 1
		elif i == 0:
			y += 1
	if y:
		print(0)
	else:
		print(x % 2)