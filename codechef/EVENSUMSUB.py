for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	if sum(a) % 2 == 0:
		print(n)
	else:
		print(n - min(min(i + 1, n - i) for i in range(n) if a[i] % 2 == 1))
