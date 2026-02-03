for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	print(sum(i >= a[0] for i in a))
