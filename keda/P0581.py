n = int(input())
z = 0
for i in range(n):
	n, f, b = input().split()
	f = float(f)
	b = int(b)
	if f >= 37.5 and b:
		print(n)
		z += 1
print(z)