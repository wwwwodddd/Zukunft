n, m = map(int, input().split())
c = [0 for i in range(n * n)]
for i in range(m):
	a = list(map(int, input().split()))[1:]
	for x in a:
		for y in a:
			c[(x - 1) * n + y - 1] = 1
if 0 in c:
	print('No')
else:
	print('Yes')