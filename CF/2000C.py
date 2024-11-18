for t in range(int(input())):
	n = int(input())
	g = {}
	p = [i for i in range(n)]
	a = input().split()
	for i in range(n):
		if a[i] in g:
			p[i] = g[a[i]]
		g[a[i]] = i
	m = int(input())
	for i in range(m):
		s = input()
		if len(s) == n and len(set(s)) == len(g):
			for j in range(len(s)):
				if s[j] != s[p[j]]:
					print('NO')
					break
			else:
				print('YES')
		else:
			print('NO')