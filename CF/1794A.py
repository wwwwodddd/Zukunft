for t in range(int(input())):
	n = int(input())
	a = []
	for i in input().split():
		if len(i) == n - 1:
			a.append(i)
	if a[0][::-1] == a[1]:
		print('YES')
	else:
		print('NO')