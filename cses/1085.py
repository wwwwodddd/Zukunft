n, m = map(int, input().split())
a = list(map(int, input().split()))
L = max(a) - 1
R = sum(a)
def ok(l):
	s = 0
	c = 1
	for i in a:
		s += i
		if s > l:
			s = i
			c += 1
	return c <= m
while L < R - 1:
	M = (L + R) // 2
	if ok(M):
		R = M
	else:
		L = M
print(R)