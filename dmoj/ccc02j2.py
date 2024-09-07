while True:
	s = input()
	if s == 'quit!':
		break
	if len(s) > 4 and s.endswith('or') and s[-3] not in 'aeiouy':
		print(s[:-2] + 'our')
	else:
		print(s)