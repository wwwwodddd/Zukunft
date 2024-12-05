n = int(input())
z = 0
m = 1e9
for i in map(int, input().split()):
	z += max(0, i - m)
	m = i
print(z)