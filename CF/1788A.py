for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	if a.count(2) % 2:
		print(-1)
	elif a.count(2) == 0:
		print(1)
	else:
		c = a.count(2) // 2
		for i in range(n):
			if a[i] == 2:
				c -= 1
				if c == 0:
					print(i + 1)
					break