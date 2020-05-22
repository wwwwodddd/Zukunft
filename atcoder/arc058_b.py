h, w, a, b = map(int, raw_input().split())
p = 10 ** 9 + 7
z = 0
s = 1
for i in range(w - b - 1):
	s = s * (h + w - b - 2 - i) * pow(i + 1, p - 2, p) % p
for i in range(h - a):
	z = (z + s) % p
	s = s * (b + i) * (h - 1 - i) * pow((i + 1) * (h + w - b - 2 - i), p - 2, p) % p
print z