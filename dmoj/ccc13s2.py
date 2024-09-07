w = int(input())
n = int(input())
a = [0, 0, 0]
z = 0
for i in range(n):
	a.append(int(input()))
for i in range(3, n + 3):
	if w >= a[i - 3] + a[i - 2] + a[i - 1] + a[i]:
		z += 1
	else:
		break
print(z)