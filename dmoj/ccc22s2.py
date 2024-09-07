x = int(input())
a = [input().split() for i in range(x)]
y = int(input())
b = [input().split() for i in range(y)]
g = int(input())
c = [input().split() for i in range(g)]
r = {}
for i in range(g):
	r[c[i][0]] = i
	r[c[i][1]] = i
	r[c[i][2]] = i
cnt = 0
for i in range(x):
	if r[a[i][0]] != r[a[i][1]]:
		cnt += 1
for i in range(y):
	if r[b[i][0]] == r[b[i][1]]:
		cnt += 1
print(cnt)
