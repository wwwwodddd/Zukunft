dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
def ok(x, y, d):
	if s[x][y] == 'X':
		return False
	for i in t:
		if i == 'F':
			x += dx[d]
			y += dy[d]
			if 0 <= x < r and 0 <= y < c and s[x][y] != 'X':
				continue
			return False
		elif i == 'L':
			d = (d - 1) % 4
		elif i == 'R':
			d = (d + 1) % 4
	return x, y

r = int(input())
c = int(input())
s = [list(input()) for i in range(r)]
n = int(input())
t = [input() for i in range(n)]
for i in range(r):
	for j in range(c):
		for d in range(4):
			p = ok(i, j, d)
			if p:
				s[p[0]][p[1]] = '*'
for i in range(r):
	print(''.join(s[i]))