from math import log10
n = int(input())
print(int(log10(2) * n) + 1)
s = '%0500d' % (pow(2, n, 10**500) - 1)
for i in range(10):
	print(s[50*i:50*i+50])