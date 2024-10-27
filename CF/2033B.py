for t in range(int(input())):
	n = int(input())
	a = []
	s = [0 for i in range(2 * n)]
	for i in range(n):
		a.append(list(map(int, input().split())))
		for j in range(n):
			s[i - j] = min(s[i - j], a[i][j])
	print(-sum(s))