import sys
s = sys.stdin.read()
for i in range(26):
	c = chr(97 + i)
	z = s.count(c)
	if z > 0:
		print('%c:%d' % (c, z))
