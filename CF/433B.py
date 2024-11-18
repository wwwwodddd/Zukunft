n = int(input())
a = [0] + list(map(int, input().split()))
b = sorted(a)
for i in range(n):
	a[i + 1] += a[i]
	b[i + 1] += b[i]
q = int(input())
for i in range(q):
	t, l, r = map(int, input().split())
	if t == 1:
		print(a[r] - a[l - 1])
	else:
		print(b[r] - b[l - 1])
