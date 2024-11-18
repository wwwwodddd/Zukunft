def cao():
	n, a, b = map(int, input().split())
	s = input()
	dx = s.count('E') - s.count('W')
	dy = s.count('N') - s.count('S')
	for c in s:
		if c == 'N':
			b -= 1
		elif c == 'S':
			b += 1
		elif c == 'E':
			a -= 1
		else:
			a += 1
		if dx == 0 and dy == 0:
			if a == 0 and b == 0:
				return True
		elif dx == 0:
			if a == 0 and b % dy == 0 and b // dy >= 0:
				return True
		elif dy == 0:
			if b == 0 and a % dx == 0 and a // dx >= 0:
				return True
		else:
			if a % dx == 0 and b % dy == 0 and a // dx == b // dy >= 0:
				return True
	return False
for t in range(int(input())):
	print(['NO', 'YES'][cao()])