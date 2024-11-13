for t in range(int(input())):
	n = int(input())
	print(['NO', 'YES'][n == 1 or n % 2 == 0])