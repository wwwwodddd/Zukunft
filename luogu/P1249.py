n = int(input())
a = []
for i in range(2, n):
	if n >= i:
		a.append(i)
		n -= i
for i in range(len(a))[::-1]:
	if n > 0:
		a[i] += 1
		n -= 1
a[-1] += n
z = 1
for i in a:
	z *= i
print(' '.join(map(str, a)))
print(z)