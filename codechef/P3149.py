for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(n):
		if a[i] > 0:
			break
		a[i] = 0
	for i in range(n)[::-1]:
		if a[i] > 0:
			break
		a[i] = 0
	print(sum(i < 0 for i in a))
