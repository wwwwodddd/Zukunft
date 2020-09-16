p = 4503599627370517
d = 1504170715041707
invd = pow(d, p - 2, p)
i = 1
a = [(d, 1)]
b = 10 ** 8
while True:
	if a[-1][0] > i * d % p:
		a.append((i * d % p, i))
	i += 1
	if a[-1][0] < 10 ** 8:
		break
for i in range(a[-1][0]-1, 0, -1):
	while a[-1][1] > i * invd % p:
		a.pop()
	a.append((i, i * invd % p))
for x, y in a:
	print(x, y)
print(len(a), sum(x for x, y in a))
# 101 1517926517777556