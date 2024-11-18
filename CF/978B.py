n = int(input())
s = input()
z = 0
for i in range(2, n):
	if s[i - 2] == s[i - 1] == s[i] == 'x':
		z += 1
print(z)