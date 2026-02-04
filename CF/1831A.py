for t in range(int(input())):
	n = int(input())
	print(*[n + 1 - int(i) for i in input().split()])