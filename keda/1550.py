input()
c = [0 for i in range(10)]
for i in map(int, input().split()):
	c[i] += 1
print(*c)