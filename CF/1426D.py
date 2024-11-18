n = int(input())
g = {0}
s = 0
z = 0
for i in map(int, input().split()):
	s += i
	if s in g:
		s = i
		g = {0, s}
		z += 1
	else:
		g.add(s)
print(z)