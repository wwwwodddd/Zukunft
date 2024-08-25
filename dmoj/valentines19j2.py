n = int(input())
z = 0
for i in range(n):
	r, g, b = map(int, input().split())
	if 240 <= r <= 255 and 0 <= g <= 200 and 95 <= b <= 220:
		z += 1
print(z)