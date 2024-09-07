n = int(input())
s = [input() for i in range(n)]
t = input()
c = [['*'] * 8 for i in range(4)]
for i in s:
	if i.startswith(t):
		d = ord(i[len(t)]) - 62
		c[d // 8][d % 8] = i[len(t)]
for i in range(4):
	print(''.join(c[i]))