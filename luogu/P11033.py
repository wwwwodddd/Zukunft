a = []
for i in range(5):
	a.append(list(map(int, input().split())))
ok = False
for i in range(5):
	if sum(a[i]) == 5:
		ok = True
	if sum(a[j][i] for j in range(5)) == 5:
		ok = True
if sum(a[i][i] for i in range(5)) == 5:
	ok = True
if sum(a[i][4-i] for i in range(5)) == 5:
	ok = True
print(['No', 'Yes'][ok])
