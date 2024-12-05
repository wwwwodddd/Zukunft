n, k = map(int, input().split())
a = list(map(int, input().split()))
def ok(x):
	d = -x
	c = 0
	for i in a:
		if i >= d + x:
			d = i
			c += 1
	return c >= k
a.sort()
L = 0
R = a[-1]
while L < R - 1:
	M = (L + R) // 2
	if ok(M):
		L = M
	else:
		R = M
print(L)
