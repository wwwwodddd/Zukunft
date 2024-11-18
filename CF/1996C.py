for t in range(int(input())):
	n, q = map(int, input().split())
	a = input()
	b = input()
	s = [[0 for j in range(26)]]
	for i in range(n):
		s.append(s[-1].copy())
		s[-1][ord(a[i]) - 97] += 1
		s[-1][ord(b[i]) - 97] -= 1
	for i in range(q):
		l, r = map(int, input().split())
		l -= 1
		z = 0
		for j in range(26):
			z += abs(s[r][j] - s[l][j])
		print(z // 2)