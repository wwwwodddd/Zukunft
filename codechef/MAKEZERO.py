for t in range(int(input())):
	n = int(input())
	s = 0
	for i in map(int, input().split()):
		s |= i
	print(s.bit_count())
