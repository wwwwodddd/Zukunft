input()
a = list(map(int, input().split()))
s = set(map(int, input().split()))
z = []
for i in a[::-1]:
	if i in s:
		z.append(i)
print(*z)