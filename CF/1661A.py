for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	for i in range(n):
		if a[i] > b[i]:
			a[i], b[i] = b[i], a[i]
	print(sum(abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]) for i in range(1, n)))