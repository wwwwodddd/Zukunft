for t in range(int(input())):
	n, x = map(int, input().split())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	print(sum(b[i] for i in range(n) if a[i] >= x))
