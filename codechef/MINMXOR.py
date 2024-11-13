for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = 0
	for i in a:
		s ^= i
	z = s
	for i in a:
		z = min(z, s ^ i)
	print(z)
