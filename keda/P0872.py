for t in range(int(input())):
	n = int(input())
	for i in range(5):
		if n >= i * 3 and (n - i * 3) % 5 == 0:
			print((n - i * 3) // 5 + i)
			break
	else:
		print(-1)