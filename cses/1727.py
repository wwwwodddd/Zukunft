n, k = map(int, input().split())
z = k
for i in range(k):
	z -= pow(i / k, n)
print('%.6f' % z)