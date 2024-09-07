A = "ABC"
B = "BABC"
C = "CCAABB"
a = b = c = 0
n = int(input())
s = input()
for i in range(n):
	if s[i] == A[i % 3]:
		a += 1
	if s[i] == B[i % 4]:
		b += 1
	if s[i] == C[i % 6]:
		c += 1
z = max(a, b, c)
print(z)
if z == a:
	print('Adrian')
if z == b:
	print('Bruno')
if z == c:
	print('Goran')