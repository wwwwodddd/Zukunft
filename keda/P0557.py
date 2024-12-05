n = int(input())
z = 0
for i in input().split():
	a = list(map(int, i))
	if a[3] > a[0] + a[1] + a[2]:
		z += 1
print(z)
