n = int(input())
s = input()
for i in range(1, n):
	j = 0
	while i + j < n and s[j] != s[i + j]:
		j += 1
	print(j)
