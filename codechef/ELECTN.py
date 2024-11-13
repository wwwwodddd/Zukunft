for t in range(int(input())):
	n, x = map(int, input().split())
	print(sum(int(i) >= x for i in input().split()))