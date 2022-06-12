for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	x = a.count(1)
	if n % 2:
		print(-1)
	else:
		print(abs(x - n // 2))
