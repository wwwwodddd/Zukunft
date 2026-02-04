for t in range(int(input())):
	n = int(input())
	s = input()
	t = set()
	l = ''
	for i in s:
		if i != l:
			if i in t:
				print('NO')
				break
			t.add(i)
		l = i
	else:
		print('YES')
