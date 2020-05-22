n = input()
s = [raw_input() for i in range(n)]
z = ''
for i in range(26):
	c = chr(i + 97)
	z += c * min(i.count(c) for i in s)
print z
