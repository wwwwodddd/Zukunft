n = int(input())
a = []
for i in range(n):
	s, g, y, m = input().split()
	a.append((s, g, int(y), int(m)))
a.sort(key=lambda i:(-i[2], -i[3]))
for i in a:
	print(*i)