for t in range(int(input())):
	input()
	s = set(map(int, input().split())) & set(map(int, input().split()))
	if s:
		print('YES')
		print(1, min(s))
	else:
		print('NO')
