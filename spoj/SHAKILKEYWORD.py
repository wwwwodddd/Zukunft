for t in range(int(input())):
	s = input()
	for i in '|$ *@.&\"!^,?':
		s = s.replace(i, ' ')
	a = [i for i in s.split() if '#' in i]
	if a:
		print('\n'.join(a))
	else:
		print('No keywords.')
