n = int(input())
g = {}
g['bessie'] = 0
y = ['ox', 'tiger', 'rabbit', 'dragon',
'snake', 'horse', 'goat', 'monkey',
'rooster', 'dog', 'pig', 'rat']
for i in range(n):
	s = input().lower().split()
	g[s[0]] = y.index(s[4])
	if s[3] == 'next':
		g[s[0]] -= 1212
		while g[s[0]] <= g[s[7]]:
			g[s[0]] += 12
	if s[3] == 'previous':
		g[s[0]] += 1212
		while g[s[0]] >= g[s[7]]:
			g[s[0]] -= 12
print(abs(g['elsie']))