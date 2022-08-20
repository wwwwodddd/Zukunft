h, w = map(int, input().split())
if h % 3 == 0 or w % 3 == 0:
	z = 0
else:
	z = min(h, w)
for i in range(h):
	a = i * w
	b = w // 2 * (h - i)
	c = (w + 1) // 2 * (h - i)
	z = min(z, max(a, b, c) - min(a, b, c))
for i in range(w):
	a = i * h
	b = h // 2 * (w - i)
	c = (h + 1) // 2 * (w - i)
	z = min(z, max(a, b, c) - min(a, b, c))
print(z)