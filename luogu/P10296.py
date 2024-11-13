import collections
t, n = map(int, input().split())
for i in range(t):
	s = input()
	c = collections.Counter(s)
	z = 0
	for j in range(len(s)):
		z += ((c[s[j]] > 1) != j % 2)
	if z == len(s) or z == 0:
		print('T')
	else:
		print('F')