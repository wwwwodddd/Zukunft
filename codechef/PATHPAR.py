for t in range(int(input())):
	n, k = map(int, input().split())
	print(['Yes', 'No'][n % 2 == 1 and k == 0])