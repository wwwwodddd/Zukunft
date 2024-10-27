import collections
p = 1000000007
x = 1
y = 1
s = 0
c = collections.Counter(input())
for i in c:
	s += c[i]
	for j in range(c[i]):
		x = x * (s - j) % p
		y = y * (j + 1) % p
print(x * pow(y, p - 2, p) % p)