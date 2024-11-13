for t in range(int(input())):
	n = int(input())
	s = sum(int(i) % 2 for i in input().split())
	print(['NO', 'YES'][s % 2 == 0 and s > 0])
