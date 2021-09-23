n=int(input())
a=[input()for i in range(n)]
for i in range(n):
	print(''.join(a[n-1-j][i]for j in range(n)))