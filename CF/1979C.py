for t in range(int(input())):
	n = int(input())
	a = [232792560 // i for i in map(int, input().split())]
	if sum(a) < 232792560:
		print(*a)
	else:
		print(-1)
