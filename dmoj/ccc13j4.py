t = int(input())
c = int(input())
a = []
for i in range(c):
	a.append(int(input()))
a.sort()
z = 0
for i in a:
	if t >= i:
		t -= i
		z += 1
print(z)
