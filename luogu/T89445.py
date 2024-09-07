n = input()
a = []
for i in range(n):
	a.append(map(int, raw_input().split()))
a.sort()
e = 0
z = 0
for x, y in a:
	if e <= x:
		e = y
		z += 1
	elif e > y:
		e = y
print z
