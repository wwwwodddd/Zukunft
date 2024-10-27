for t in range(int(input())):
	n = int(input())
	a = sorted([list(map(int, input().split())) for i in range(n)], key=lambda a: sum(a))
	for x, y in a:
		print(x, y, end=' ')
	print()
