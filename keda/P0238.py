import collections
s = input()
c = collections.Counter(s)
for i in s:
	if c[i] == 1:
		print(i)
		break
else:
	print('no')