n = int(input())
z = 0
m = 1e9
for i in map(int, input().split()):
	z = max(z, i - m)
	m = min(m, i)
print(z)