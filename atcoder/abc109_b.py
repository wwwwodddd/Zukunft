n = input()
a = []
for i in range(n):
	a.append(raw_input())
for i in range(1, n):
	if a[i - 1][-1] != a[i][0]:
		print 'No'
		exit()
if len(set(a)) != n:
	print 'No'
	exit()
print 'Yes'