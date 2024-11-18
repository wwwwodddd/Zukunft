for t in range(int(input())):
	n, m = map(int, input().split())
	s = []
	for i in range(n):
		s.append(input())
	c = 0
	for i in range(min(n, m) // 2):
		z = s[i][i:m-i]
		for j in range(i + 1, n - i - 1):
			z += s[j][m - i - 1]
		z += s[n-1-i][i:m-i][::-1]
		for j in range(i + 1, n - i - 1)[::-1]:
			z += s[j][i]
		z += z[:3]
		c += z.count('1543')
	print(c)
