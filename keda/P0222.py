n = int(input())
z = []
s = set()
for i in map(int, input().split()):
	if i not in s:
		s.add(i)
		z.append(i)
print(*z)
