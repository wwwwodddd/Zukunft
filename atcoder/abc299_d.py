import sys
n = int(input())
L = 0
R = n
while L < R - 1:
	M = (L + R) // 2
	print('?', M)
	sys.stdout.flush()
	o = input()
	if o == '0':
		L = M
	else:
		R = M
print('!', L)