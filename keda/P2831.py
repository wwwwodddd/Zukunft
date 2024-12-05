n = int(input())
z = ''
a = list(map(int, input().split()))
z = []
s = set()
for i in a:
	if i not in s:
		s.add(i)
		z.append(i)
print(*z)