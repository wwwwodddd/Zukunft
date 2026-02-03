for t in range(int(input())):
	n, q = map(int, input().split())
	s = sum(map(int, input().split()))
	for i in range(q):
		l, r = map(int, input().split())
		s += (r - l + 1) % 2
	print(s)
