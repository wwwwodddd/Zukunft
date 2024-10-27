import re
for t in range(int(input())):
	input()
	s = input().lower()
	if re.match('^m+e+o+w+$', s):
		print('YES')
	else:
		print('NO')