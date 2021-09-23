n = int(input())
c = [0 for i in range(n + 1)]
c[0] = 3
z = 1
for i in map(int, input().split()):
	z = z * c[i] % 1000000007
	c[i] -= 1
	c[i + 1] += 1
print(z)