n = int(input())
a = list(map(int, input().split()))
s = set()
b = []
for i in a[::-1]:
	if i not in s:
		b.append(i)
	s.add(i)
print(len(b))
print(*b[::-1])