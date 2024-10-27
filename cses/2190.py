def xm(x1, x2, y1, y2):
	return x1 * y2 - x2 * y1
def ok(x2, y2, x3, y3, x4, y4):
	return xm(x2, y2, x3, y3) * xm(x2, y2, x4, y4) <= 0
def include(x1, x2, x3, x4):
	if max(x1, x2) < min(x3, x4):
		return False
	if max(x3, x4) < min(x1, x2):
		return False
	return True
for t in range(int(input())):
	x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())
	if ok(x2 - x1, y2 - y1, x3 - x1, y3 - y1, x4 - x1, y4 - y1) \
		and ok(x4 - x3, y4 - y3, x1 - x3, y1 - y3, x2 - x3, y2 - y3) \
		and include(x1, x2, x3, x4) and include(y1, y2, y3, y4):
		print('YES')
	else:
		print('NO')