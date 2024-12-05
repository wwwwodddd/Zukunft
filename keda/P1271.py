n = int(input())
s = input()
t = 0
z = ''
for i in s:
	if t % 7 == int(i):
		z += 'G'
	else:
		z += 'X'
	t = t * 10 + int(i)
print(z)