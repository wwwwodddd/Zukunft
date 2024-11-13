for t in range(int(input())):
	x = int(input())
	if x <= 100:
		print(x)
	elif x <= 1000:
		print(x - 25)
	elif x <= 5000:
		print(x - 100)
	else:
		print(x - 500)