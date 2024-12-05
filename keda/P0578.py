import collections
c = [0 for i in range(256)]
for i in input():
	c[ord(i)] += 1
m = max(c)
print(chr(c.index(m)), m)