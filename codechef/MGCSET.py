for t in range(int(input())):
	n, m = map(int, input().split())
	s = sum(i % m == 0 for i in map(int, input().split()))
	print(2 ** s - 1)
