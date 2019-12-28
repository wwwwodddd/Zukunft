t = input()
for tt in range(t):
	n = input()
	if n == 1:
		print 0
	elif 2 <= n <= 5:
		print -1
	elif n == 6:
		print 9
	elif n == 7:
		print 15
	else:
		print (n * (n - 1) / 2 - n + 2) % 1000000007