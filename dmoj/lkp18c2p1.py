import heapq
n, m = map(int, input().split())
a = list(map(int, input().split()))
heapq.heapify(a)
for i in range(m):
	x = heapq.heappop(a)
	print(x)
	heapq.heappush(a, x + 1)
