input()
c = [0 for i in range(11)]
for i in map(int, input().split()):
	c[i] += 1
print(*c[1:])