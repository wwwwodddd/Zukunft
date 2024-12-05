s = input()
x, y = input().split()
z = 0
for i in s:
	if x <= i <= y:
		z += 1
print(z)