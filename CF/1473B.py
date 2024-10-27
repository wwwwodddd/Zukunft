import math
for t in range(int(input())):
	a = input()
	b = input()
	l = math.lcm(len(a), len(b))
	if l // len(a) * a == l // len(b) * b:
		print(l // len(a) * a)
	else:
		print(-1)