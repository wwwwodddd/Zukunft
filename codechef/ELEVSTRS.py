for t in range(int(input())):
	n, a, b = map(int, input().split())
	print(['Stairs', 'Elevator'][b * b > 2 * a * a])