m = int(input())
input()
z = 0
for i in map(int, input().split()):
	if m >= i:
		m -= i
	else:
		z += 1
print(z)