n = int(input())
s = sum(map(int, input().split()))
z = 1
for i in range(1, n):
	t = sum(map(int, input().split()))
	if t > s:
		z += 1
print(z)