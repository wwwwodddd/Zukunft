n = int(input())
if n == 2:
	print(1)
elif n == 3:
	print(2)
elif n % 3 == 0:
	print(3 ** (n // 3))
elif n % 3 == 1:
	print(3 ** ((n - 4) // 3) * 4)
elif n % 3 == 2:
	print(3 ** ((n - 2) // 3) * 2)
