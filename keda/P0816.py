input()
a = sorted(map(int, input().split()))
s = 200
z = 0
for i in a:
	if s >= i:
		s -= i
		z += 1
print(z)