input()
for x,y in sorted((y,x)for x,y in enumerate(map(int,input().split())))[::-1]:
	print(y+1)