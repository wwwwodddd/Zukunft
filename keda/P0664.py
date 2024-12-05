n = int(input())
a = sorted([list(map(int, input().split())) for i in range(n)])
for i in a:
	print(*i)