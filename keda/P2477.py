input()
z = s = 0
for i in map(int, input().split()):
	if i:
		s += 1
	else:
		s = 0
	z = max(z, s)
print(z)
