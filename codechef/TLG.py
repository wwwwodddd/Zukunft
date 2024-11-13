n = int(input())
d = 0
mn = mx = 0
for i in range(n):
	s, t = map(int, input().split())
	d += s - t
	mx = max(mx, d)
	mn = min(mn, d)
if mx + mn > 0:
	print(1, mx)
else:
	print(2, -mn)