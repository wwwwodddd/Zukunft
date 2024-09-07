m = int(input())
n = int(input())
z = 0
for i in range(1, m + 1):
	if 1 <= 10 - i <= n:
		z += 1
if z == 1:
	print('There is', z, 'way to get the sum 10.')
else:
	print('There are', z, 'ways to get the sum 10.')