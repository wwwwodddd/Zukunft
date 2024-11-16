n = int(input())
s = input()
z = 0
for i in range(n):
	t = input()
	c = 0
	for j in range(len(t)):
		c += (s[j] == t[j])
	if c * 2 >= len(t):
		z += 1
print(z)
print(['Good job!', 'Make persistent efforts.'][z > 0])