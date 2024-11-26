for t in range(int(input())):
	n = int(input())
	s = 0
	t = 0
	for i in range(n):
		x, y = input().split()
		x = sum(map(int, x))
		y = sum(map(int, y))
		if x > y:
			s += 1
		elif x < y:
			t += 1
		else:
			s += 1
			t += 1
	if s > t:
		print(0, s)
	elif s < t:
		print(1, t)
	else:
		print(2, s)