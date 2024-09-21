for t in range(int(input())):
	n = int(input())
	z = 0
	for i in map(int, input().split()):
		z ^= i
	print(['first', 'second'][z == 0])