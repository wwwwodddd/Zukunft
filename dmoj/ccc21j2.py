n = int(input())
zs = ''
zb = 0
for i in range(n):
	s = input()
	b = int(input())
	if zb < b:
		zb = b
		zs = s
print(zs)
