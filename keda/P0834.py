input()
z = s = 0
for i in map(int, input().split()):
	z += s * i
	s += i
print(z)