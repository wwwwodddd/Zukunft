a = []
while True:
	s = input()
	if s == 'SCHOOL':
		break
	a.append(s)
while len(a) > 1:
	if a[-1] == 'R':
		print('Turn LEFT onto', a[-2], 'street.')
	else:
		print('Turn RIGHT onto', a[-2], 'street.')
	a.pop()
	a.pop()
if a[-1] == 'R':
	print('Turn LEFT into your HOME.')
else:
	print('Turn RIGHT into your HOME.')
