for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	print(sum(a) - n * min(a))