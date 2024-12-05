while True:
	try:
		n = int(input())
		for i in range(n):
			print((n - 1 - i) * ' ' + (2 * i + 1) * '*')
	except:
		break