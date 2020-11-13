c = [0, 0, 0]
m = [0, 0, 0]
c[0], m[0] = map(int, raw_input().split())
c[1], m[1] = map(int, raw_input().split())
c[2], m[2] = map(int, raw_input().split())
for i in range(100):
	m[(i + 1) % 3] += m[i % 3]
	m[i % 3] = 0
	if m[(i + 1) % 3] > c[(i + 1) % 3]:
		m[i % 3] = m[(i + 1) % 3] - c[(i + 1) % 3]
		m[(i + 1) % 3] = c[(i + 1) % 3]
print m[0]
print m[1]
print m[2]