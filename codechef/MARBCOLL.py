for t in range(int(input())):
	n, m = map(int, input().split())
	print(m - len(set(map(int, input().split()))))