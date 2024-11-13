for t in range(int(input())):
	x, y, z = map(float, input().split())
	a = x > 50
	b = y < 0.7
	c = z > 5600
	if a and b and c:
		print(10)
	elif a and b:
		print(9)
	elif b and c:
		print(8)
	elif a and c:
		print(7)
	elif a or b or c:
		print(6)
	else:
		print(5)
