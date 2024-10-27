a = []
for i in range(8):
	a.append(list(map(int, input().split())))
a.sort()
a.append([a[3][0], a[1][1]])
a.sort()
if a[0][0] == a[3][0] or a[3][0] == a[6][0]:
	print('ugly')
elif a[0][1] == a[1][1] or a[1][1] == a[2][1]:
	print('ugly')
else:
	for i in range(9):
		if a[i][0] != a[i // 3 * 3][0] or a[i][1] != a[i % 3][1]:
			print('ugly')
			break
	else:
		print('respectable')