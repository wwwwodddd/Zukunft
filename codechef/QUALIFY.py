for t in range(int(input())):
	x, a, b = map(int, input().split())
	print(['NotQualify', 'Qualify'][x <= a + 2 * b])
