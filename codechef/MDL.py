for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = {min(a), max(a)}
	print(*[i for i in a if i in s])
