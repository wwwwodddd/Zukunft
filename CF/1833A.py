for t in range(int(input())):
	input()
	s = input()
	print(len(set(s[i:i+2] for i in range(len(s) - 1))))
