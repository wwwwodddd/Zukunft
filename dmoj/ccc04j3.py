n = int(input())
m = int(input())
a = [input() for i in range(n)]
b = [input() for i in range(m)]
for i in a:
	for j in b:
		print(i, 'as', j)