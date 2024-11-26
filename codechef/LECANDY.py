for t in range(int(input())):
	n, c = map(int, input().split())
	print(['No', 'Yes'][c >= sum(map(int, input().split()))])
