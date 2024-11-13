n = int(input())
m, c = map(int, input().split())
z = [0, 0]
for i in range(n):
	x, y, p = map(int, input().split())
	if x * m + c < y:
		z[0] += p
	else:
		z[1] += p
print(max(z))