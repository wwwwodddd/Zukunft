for t in range(int(input())):
	n = int(input())
	s = input()
	print(min(s.count('1'), 1 + s.count('0')))
