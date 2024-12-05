n = int(input())
while n > 1:
	if n % 2 == 0:
		print('%d/2=%d' % (n, n // 2))
		n //= 2
	else:
		print('%d*3+1=%d' % (n, n * 3 + 1))
		n = n * 3 + 1
print('End')
