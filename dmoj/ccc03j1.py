t = int(input())
s = int(input())
h = int(input())
for i in range(t):
	print('*' + ' ' * s + '*' + ' ' * s + '*')
print('*' * (3 + s * 2))
for i in range(h):
	print(' ' * s + ' *')
