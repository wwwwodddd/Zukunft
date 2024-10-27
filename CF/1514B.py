for t in range(int(input())):
	n, k = map(int, input().split())
	print(pow(n, k, 1000000007))