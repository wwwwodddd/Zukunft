for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()), reverse=True)
	print(sum(a[::2]))