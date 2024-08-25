n = int(input())
p = []
w = []
d = []
for i in range(n):
	x, y, z = map(int, input().split())
	p.append(x)
	w.append(y)
	d.append(z)
L = -1
R = 1000000000
def ok(M):
	mn = 0
	mx = 1000000000
	for i in range(n):
		mn = max(mn, p[i] - (M // w[i]) - d[i])
		mx = min(mx, p[i] + (M // w[i]) + d[i])
	return mn <= mx
while L < R - 1:
	M = (L + R) // 2
	if ok(M):
		R = M
	else:
		L = M
print(R)