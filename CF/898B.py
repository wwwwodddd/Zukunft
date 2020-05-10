n = input()
a = input()
b = input()
if a > b:
	for i in xrange(min(b, n / a + 1)):
		if (n - i * a) % b == 0:
			print 'YES\n', i, (n - i * a) / b
			break
	else:
		print 'NO'
else:
	for i in xrange(min(a, n / b + 1)):
		if (n - i * b) % a == 0:
			print 'YES\n', (n - i * b) / a, i
			break
	else:
		print 'NO'
