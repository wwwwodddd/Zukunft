n = int(input())
while n % 4 == 0:
	n //= 4
if n == 1:
	print('true')
else:
	print('false')