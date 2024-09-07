n = int(input())
g = {}
a = input().split()
b = input().split()
for i in range(n):
	g[a[i]] = b[i]
for i in range(n):
	if g[a[i]] == a[i]:
		print('bad')
		break
	if g[g[a[i]]] != a[i]:
		print('bad')
		break
else:
	print('good')