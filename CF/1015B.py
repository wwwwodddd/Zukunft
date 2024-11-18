n = int(input())
s = input()
t = input()
if sorted(s) != sorted(t):
	print(-1)
else:
	z = []
	s = list(s)
	for i in range(n):
		for j in range(i, n):
			if s[j] == t[i]:
				for j in range(j, i, - 1):
					s[j], s[j - 1] = s[j - 1], s[j]
					z.append(j)
				break
	print(len(z))
	print(*z)