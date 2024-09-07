import sys

r = 2000000000
l = 1

while l <= r:
	m = (l + r) // 2
	print(m)
	sys.stdout.flush()
	s = input()
	if s[0] == "S":
		l = m + 1
	elif s[0] == "F":
		r = m - 1
	else:
		break
