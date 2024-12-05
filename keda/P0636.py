n = int(input())
while n % 3 == 0:
	n //= 3
if n == 1:
	print('true')
else:
	print('false')