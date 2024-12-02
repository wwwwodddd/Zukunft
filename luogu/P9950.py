n = int(input())
a = input()
b = input()
z = 0
l = 0
for i in range(n):
	if a[i] == b[i]:
		l = 0
	else:
		if l == 0:
			z += 1
		l = 1
print(z)