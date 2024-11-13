for t in range(int(input())):
	input()
	s = input()
	if len(s) == len(set(s)):
		print(-1)
	else:
		print(len(s) - 2)
