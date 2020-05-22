from collections import *
input()
a = Counter(map(int, raw_input().split()))
z = 0
for i in a:
	if a[i] >= i:
		z += a[i] - i
	else:
		z += a[i]
print z