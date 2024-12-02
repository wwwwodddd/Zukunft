s = input()
t = input()
p = 26
c = 0
for i in t:
	if s.index(i) <= p:
		c += 1
	p = s.index(i)
print(c)