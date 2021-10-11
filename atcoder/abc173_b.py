a=['AC','WA','TLE','RE']
b=[0,0,0,0]
for i in range(int(input())):
	b[a.index(input())]+=1
for i in range(4):
	print(a[i],'x',b[i])