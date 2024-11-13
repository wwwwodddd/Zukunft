g = {'A' : 'T', 'T' : 'A', 'C' : 'G', 'G' : 'C'}
for t in range(int(input())):
	input()
	print(''.join(g[i] for i in input()))