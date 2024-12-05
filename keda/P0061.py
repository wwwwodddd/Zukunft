n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
for i in zip(*a):
	print(*i)