a = []
for i in range(10 ** 5):
	for j in range(10 ** 3):
		s = i ** 2 + j ** 3
		if str(s) == str(s)[::-1]:
			a.append(s)
a = sorted(a)
s = 0
for i in range(3, len(a)):
	if a[i - 3] == a[i]:
		s += a[i]
		print a[i]
print len(a)
print s