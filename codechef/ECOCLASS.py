for t in range(int(input())):
	input()
	print(sum(x == y for x, y in zip(map(int, input().split()), map(int, input().split()))))
