n = input()
c0 = 0
cn = 0
for i in map(int, input().split()):
	if i == 0:
		c0 += 1
	elif i < 0:
		cn += 1
if c0:
	print(0)
elif cn & 1:
	print(-1)
else:
	print(1)