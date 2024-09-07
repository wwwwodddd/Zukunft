t = int(input())
for tt in range(t):
	n, m = map(int, input().split())
	sx = 0
	sy = 0
	c = 0
	for i in range(n):
		s = input()
		for j in range(m):
			if s[j] == '#':
				sx += i
				sy += j
				c += 1
	print(sx // c + 1, sy // c + 1)