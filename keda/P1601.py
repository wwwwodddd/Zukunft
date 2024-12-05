n, m = map(int, input().split())
z = 1
for i in map(int, input().split()):
	if i > m:
		z += 1
print(z)