t = int(input())
for tt in range(t):
	n, m = map(int, input().split())
	s = [input() for i in range(n)]
	t = [input() for i in range(n)]
	def ok():
		for i in range(n):
			c = 0
			for j in range(m):
				c += int(s[i][j]) - int(t[i][j])
			if c % 3 != 0:
				return False
		for j in range(m):
			c = 0
			for i in range(n):
				c += int(s[i][j]) - int(t[i][j])
			if c % 3 != 0:
				return False
		return True
	if ok():
		print('YES')
	else:
		print('NO')
