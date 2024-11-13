for t in range(int(input())):
	s = input()
	print(sum(int(i) for i in s if i.isdigit()))
