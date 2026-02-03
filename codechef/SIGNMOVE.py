for t in range(int(input())):
	n = int(input())
	if n & 1:
		print(-n // 2)
	else:
		print(n // 2)