x = int(input())
m = int(input())
for i in range(1, m):
	if x * i % m == 1:
		print(i)
		break
else:
	print('No such integer exists.')