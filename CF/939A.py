n = int(input())
a = [0] + list(map(int, input().split()))
for i in range(1, n + 1):
	if a[a[a[i]]] == i:
		print('YES')
		break
else:
	print('NO')