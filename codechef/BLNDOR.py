for t in range(int(input())):
	input()
	print(['NO', 'YES'][list(map(int, input().split())).count(2) % 8 == 0])
