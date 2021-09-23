n = int(input())
s = input()
x = int(s, 2)
c = s.count('1')
if c > 1:
	a = x % (c - 1)
else:
	a = 0
b = x % (c + 1)
for i in range(n):
	if s[i] == '0':
		t = (b + pow(2, n - i - 1, c + 1)) % (c + 1)
		z = 1
	else:
		if c == 1:
			t = 0
			z = 0
		else:
			t = (a - pow(2, n - i - 1, c - 1)) % (c - 1)
			z = 1
	while t:
		t %= bin(t).count('1')
		z += 1
	print(z)