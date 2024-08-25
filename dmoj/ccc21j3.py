d = ''
while True:
	s = input()
	if s == '99999':
		break
	elif (int(s[0]) + int(s[1])) % 2 == 1:
		d = 'left'
	elif (int(s[0]) + int(s[1])) % 2 == 0 and (int(s[0]) + int(s[1])) > 0:
		d = 'right'
	print(d, s[2:])
