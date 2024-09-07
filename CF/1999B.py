def ok(a1, a2, b1, b2):
	s = 0
	if a1 > b1:
		s += 1
	elif a1 < b1:
		s -= 1
	if a2 > b2:
		s += 1
	elif a2 < b2:
		s -= 1
	return s > 0
for t in range(int(input())):
	a1, a2, b1, b2 = map(int, input().split())
	z = 0
	if ok(a1, a2, b1, b2):
		z += 2
	if ok(a1, a2, b2, b1):
		z += 2
	print(z)