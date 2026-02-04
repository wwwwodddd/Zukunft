n, b, d = map(int, input().split())
s = 0
z = 0
for i in map(int, input().split()):
	if i <= b:
		s += i
		if s > d:
			s = 0
			z += 1
print(z)