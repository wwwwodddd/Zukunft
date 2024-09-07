s = set()
for i in range(int(input()) * 2 - 1):
	t = input()
	if t in s:
		s.remove(t)
	else:
		s.add(t)
print(s.pop())