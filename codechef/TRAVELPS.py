for t in range(int(input())):
	n, a, b = map(int, input().split())
	s = input()
	print(a * s.count('0') + b * s.count('1'))
