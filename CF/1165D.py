for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	s = set()
	z = max(a) * min(a)
	i = 2
	while i * i <= z:
		if z % i == 0:
			s.add(i)
			s.add(z // i)
		i += 1
	if s == set(a):
		print(z)
	else:
		print(-1)