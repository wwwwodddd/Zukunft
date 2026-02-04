import collections
k = int(input())
s = input()
l = ''
c = 0
for i in s:
	if l != i:
		l = i
		c = 0
	c += 1
	if c >= k:
		print(i)
		break
else:
	print('No')
