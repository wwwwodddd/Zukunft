n, b, p, bv, pv = map(int, raw_input().split())
x = map(int, raw_input().split())
s = 'useless'
for i in x:
	if abs(p - i) < abs(p - b) + abs(b - i) and abs(i - p) * bv < abs(i - b) * pv:
		s = 'useful'
print s