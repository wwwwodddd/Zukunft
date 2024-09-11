a = int(input())
b = int(input())
c = int(input())
d = int(input())
s = int(input())
x = (s // (a + b)) * (a - b)
y = (s // (c + d)) * (c - d)
if s % (a + b) < a:
	x += s % (a + b)
else:
	x += a - (s % (a + b) - a)
if s % (c + d) < c:
	y += s % (c + d)
else:
	y += c - (s % (c + d) - c)
if x > y:
	print('Nikky')
elif x < y:
	print('Byron')
else:
	print('Tied')