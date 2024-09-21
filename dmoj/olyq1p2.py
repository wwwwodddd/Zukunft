n = int(input())
a = list(map(int, input().split()))
d = 0
z = 1
for i in range(1, n):
	if a[i] > a[i - 1]:
		if d != -1:
			d = -1
			z += 1
	elif a[i] < a[i - 1]:
		if d != 1:
			d = 1
			z += 1
print(z)