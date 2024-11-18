for t in range(int(input())):
	n = int(input())
	s = input()
	print(['NO', 'YES'][list(s) == sorted(s)])