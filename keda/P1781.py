while True:
	s = input().strip()
	if s == '0':
		break
	if sum(map(int, s)) % 2:
		print(s)