for t in range(int(input())):
	n, k = map(int, input().split())
	print(sum((i + k) % 7 == 0 for i in map(int, input().split())))