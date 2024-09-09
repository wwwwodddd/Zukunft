import heapq
# import time
# st = time.time()
# print(time.time() - st)
n, m = map(int, input().split())
a = [0 for i in range(m)]
b = [0 for i in range(m)]
p = [0 for i in range(n + 1)]
for i in range(m):
	y, x, t = map(int, input().split())
	b[i] = (x, y, t)
	p[x] += 1
# print(time.time() - st)
for i in range(n):
	p[i + 1] += p[i]
for i in range(m):
	p[b[i][0]] -= 1
	a[p[b[i][0]]] = b[i]
p.append(m)
# print(time.time() - st)
d = [[1000000000000000000, 1000000000000000000] for _ in range(n+1)]
d[n][0] = 0
q = []
heapq.heappush(q, (d[n][0], n, 0))
while q:
	t, u, o = heapq.heappop(q)
	if t != d[u][o]:
		continue
	if u == 1 and o == 1:
		break
	for i in range(p[u], p[u + 1]):
		_, v, w = a[i]
		if d[v][o] > d[u][o] + w:
			d[v][o] = d[u][o] + w
			heapq.heappush(q, (d[v][o], v, o))
		if o == 0 and d[v][1] > d[u][0] + w // 2:
			d[v][1] = d[u][0] + w // 2
			heapq.heappush(q, (d[v][1], v, 1))
print(d[1][1])
# print(time.time() - st)
