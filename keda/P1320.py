a = int(input())
b = int(input())
c = int(input())
for i in range(a):
	if c >= i * b and (c - i * b) % a == 0:
		print('he can')
		break
else:
	print('he cannot')
