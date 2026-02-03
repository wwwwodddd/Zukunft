for t in range(int(input())):
	s = input()
	print(sum((ord('ADVITIYA'[i]) - ord(s[i])) % 26 for i in range(len(s))))