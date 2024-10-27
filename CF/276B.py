import collections
c = collections.Counter(input())
s = 0
for i in c:
	s += c[i] % 2
if s % 2 == 1 or s == 0:
	print('First')
else:
	print('Second')