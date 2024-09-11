c = {}
n = int(input())
for i in range(n):
	s = input()
	for j in range(len(s)):
		if s[j] == 'Y':
			if j not in c:
				c[j] = 0
			c[j] += 1
d = max(c.values())
a = [i + 1 for i in c if c[i] == d]
a.sort()
print(','.join(map(str, a)))