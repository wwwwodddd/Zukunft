for t in range(int(input())):
	n = int(input())
	print(sum(int(i) >= 1000 for i in input().split()))