import heapq
n = int(input())
s = 0
q = []
for i in map(int, input().split()):
	s += i
	heapq.heappush(q, i)
	while s < 0:
		s -= q[0]
		heapq.heappop(q)
print(len(q))