a = ['A', 'B', 'C', 'D', 'E']
while True:
	b = int(input())
	n = int(input())
	if b == 1:
		n %= 5
		a = a[n:] + a[:n]
	elif b == 2:
		n = (5 - n) % 5
		a = a[n:] + a[:n]
	elif b == 3:
		if n & 1:
			a[0], a[1] = a[1], a[0]
	else:
		print(*a)
		break
