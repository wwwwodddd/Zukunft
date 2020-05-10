n = input()
g = {}
for i in range(n):
	s = raw_input()
	if s not in g:
		print 'OK'
		g[s] = 1
	else:
		print s + str(g[s])
		g[s] += 1
