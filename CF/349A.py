n = int(input())
x = 0
y = 0
for i in map(int, input().split()):
	if i == 25:
		x += 1
	elif i == 50:
		if x >= 1:
			x -= 1
			y += 1
		else:
			print('NO')
			break
	else:
		if x >= 1 and y >= 1:
			x -= 1
			y -= 1
		elif x >= 3:
			x -= 3
		else:
			print('NO')
			break
else:
	print('YES')
