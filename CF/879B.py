n, k = map(int, raw_input().split())
b, c = 0, 0
for v in map(int, raw_input().split()):
	if b > 0: c = [1, c + 1][b > v]
	b = max(b, v)
	if c == k: break
print b