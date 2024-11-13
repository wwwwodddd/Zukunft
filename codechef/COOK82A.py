for t in range(int(input())):
	g = {}
	for i in range(4):
		x, y = int(input())
		g[x] = int(y)
	if g['RealMadrid'] < g['Malaga'] and g['Barcelona'] > g['Eibar']:
		print('Barcelona')
	else:
		print('RealMadrid')
