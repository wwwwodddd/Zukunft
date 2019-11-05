x = 0
def P(x):
	if x < 2:
		return "N"
	for i in range(2, x):
		if x % i == 0:
			return "N"
	return "P"

p = [P(i) for i in range(501)]
def calc(s, x):
	re = ""
	for i in range(14):
		re += p[s]
		if s == 1:
			s += 1
		elif s == 500:
			s -= 1
		elif x >> i & 1:
			s += 1
		else:
			s -= 1
	re += p[s]
	return re


#print calc(1, 65535)
#exit()
for i in range(1, 501):
	if i % 50 == 0:
		print i
	for j in range(2 ** 14):
		s = calc(i, j)
		t = 'PPPPNNPPPNPPNPN'
		c = 0
		for k in range(15):
			if s[k] == t[k]:
				c += 1
		x += 2 ** c

y = 500 * 2 ** 14 * 3 ** 15

def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x % y)
g = gcd(x, y)
x /= g
y /= g
print x, y

