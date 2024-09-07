a = []
while True:
	s, t = input().split()
	a.append((int(t), s))
	if s == 'Waterloo':
		break
print(min(a)[1])