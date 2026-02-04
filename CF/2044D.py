for t in range(int(input())):
	n = int(input())
	s = set()
	a = []
	for i in map(int, input().split()):
		if i not in s:
			s.add(i)
			a.append(i)
	for i in range(1, n + 1):
		if i not in s:
			s.add(i)
			a.append(i)
	print(*a)
