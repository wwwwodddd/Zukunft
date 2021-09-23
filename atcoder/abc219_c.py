o = input()
p = [o.index(chr(97+i))for i in range(26)]
n = int(input())
a = []
def F(s):
	t = ''
	for i in s:
		t += chr(p[ord(i)-97]+97)
	return t
for i in range(n):
	s = input()
	a.append((F(s), s))
a.sort()
for x, y in a:
	print(y)