for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	k = int(input())
	print(sum(i <= a[k - 1] for i in a))
