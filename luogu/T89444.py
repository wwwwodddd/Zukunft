while True:
	n = input()
	if n == 0:
		break
	ans = 0.0
	if n <= 4:
		ans = 10.0
	elif n % 8 <= 4:
		ans = n / 8 * 18.0 + n % 8 * 2.4
	else:
		ans = n / 8 * 18.0 + 10.0 + (n % 8 - 4) * 2.0
	print '%.1f' % ans
