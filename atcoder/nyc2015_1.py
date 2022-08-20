n = int(input())
s = '{:b}'.format(n)
if s == s[::-1]:
	print('Yes')
else:
	print('No')