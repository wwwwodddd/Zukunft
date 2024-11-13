for t in range(int(input())):
	n = int(input())
	s = sum(map(int, input().split()))
	print(['NO', 'YES'][n % 2 == s % 2])
