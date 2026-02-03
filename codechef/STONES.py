for t in range(int(input())):
	s = input()
	t = input()
	print(sum(i in s for i in t))
