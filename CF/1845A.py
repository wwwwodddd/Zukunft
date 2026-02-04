for t in range(int(input())):
	n, k, x = map(int, input().split())
	if x > 1:
		print('YES')
		print(n)
		print(*[1 for i in range(n)])
	elif 2 <= k and n % 2 == 0:
		print('YES')
		print(n // 2)
		print(*[2 for i in range(n // 2)])
	elif 3 <= k and n >= 3:
		print('YES')
		print(n // 2)
		print(*([3] + [2 for i in range(n // 2 - 1)]))
	else:
		print('NO')