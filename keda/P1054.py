s = input()
c = 0
n = len(s) // 2
for i in 'aeoiuAEIOU':
	c += s[:n].count(i) - s[n:].count(i)
print(['NO', 'YES'][c == 0])