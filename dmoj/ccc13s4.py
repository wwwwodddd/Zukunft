import collections
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [[] for i in range(n + 1)]
for i in range(m):
	x, y = map(int, input().split())
	a[x].append(y)

p, q = map(int, input().split())

def bfs(x, y):
	d = [-1 for _ in range(n + 1)]
	q = collections.deque()
	q.append(x)
	d[x] = 0
	while q:
		x = q.popleft()
		for i in a[x]:
			if d[i] == -1:
				d[i] = d[x] + 1
				if i == y:
					return True
				q.append(i)
	return False

if bfs(p, q):
	print('yes')
elif bfs(q, p):
	print('no')
else:
	print('unknown')