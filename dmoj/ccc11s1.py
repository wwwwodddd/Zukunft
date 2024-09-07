n = int(input())
z = 0
for i in range(n):
	s = input().lower()
	z += s.count('t') - s.count('s')
if z > 0:
	print('English')
else:
	print('French')