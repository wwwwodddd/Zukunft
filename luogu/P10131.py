t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	s = set()
	for i in range(1, n):
		if a[i - 1] == a[i]:
			s.add(a[i])
	for i in range(2, n):
		if a[i - 2] == a[i]:
			s.add(a[i])
	if len(s) == 0:
		s.add(-1)
	print(*sorted(s))
