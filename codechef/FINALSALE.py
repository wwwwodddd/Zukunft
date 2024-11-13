for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = sum(a)
	s = 0
	for i in a:
		z = max(z, s + i * 2)
		s += i
	print(z)
