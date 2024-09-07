n = int(input())
s = ['*x*',' xx','* *']
for i in range(3):
	t = ''
	for j in range(3):
		t += s[i][j] * n
	for k in range(n):
		print(t)
