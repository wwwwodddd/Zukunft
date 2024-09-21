n = int(input())
if n == 1:
	print(1)
elif n < 4:
	print('NO SOLUTION')
elif n == 4:
	print('2 4 1 3')
else:
	for i in range(n):
		if i & 1:
			print(i // 2 + 1 + (n + 1) // 2, end=' ')
		else:
			print(i // 2 + 1, end=' ')