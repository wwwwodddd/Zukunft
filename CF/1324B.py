for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = set()
	for i in range(1, n):
		if a[i] in s:
			print('YES')
			break
		s.add(a[i - 1])
	else:
		print('NO')
