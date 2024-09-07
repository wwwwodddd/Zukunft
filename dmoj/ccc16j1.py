a = [input() for i in range(6)]
c = a.count('W')
if c > 4:
	print(1)
elif c > 2:
	print(2)
elif c > 0:
	print(3)
else:
	print(-1)