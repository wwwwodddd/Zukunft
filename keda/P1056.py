a = input().split()
for i in range(len(a)):
	if len(a[i]) < 3:
		a[i] = a[i].lower()
	else:
		a[i] = a[i].capitalize()
print(*a)