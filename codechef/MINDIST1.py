for t in range(int(input())):
	n = int(input())
	s = input()
	if '1' in s[::2] and '1' in s[1::2]:
		print(1)
	else:
		print(2)
