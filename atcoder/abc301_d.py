s = input()[::-1]
n = int(input())
z = 0
for i in range(len(s)):
	if s[i] == '1':
		z |= 1 << i
for i in range(len(s))[::-1]:
	if s[i] == '?' and z + 2 ** i <= n:
		z |= 1 << i
if z > n:
	z = -1
print(z)
