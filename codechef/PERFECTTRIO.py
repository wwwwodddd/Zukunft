for t in range(int(input())):
	a = list(map(int, input().split()))
	print(['NO', 'YES'][sum(a) == max(a) * 2])
