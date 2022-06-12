for t in range(int(input())):
	a, b = map(int, input().split())
	if a % 3 == 0 or b % 3 == 0:
		print(0)
	elif a % 3 == b % 3:
		print(1)
	else:
		print(2)