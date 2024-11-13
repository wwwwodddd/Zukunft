for t in range(int(input())):
	a = sorted(map(int, input().split()))
	print(['NO', 'YES'][a[0] == a[1] and a[2] == a[3]])
