input()
c = [0 for i in range(2)]
for i in map(int, input().split()):
	c[i % 2] += 1
print(min(c))