f = [0 for i in range(101)]
f[0] = 1
for i in range(4, 101):
	f[i] += f[i - 4]
for i in range(7, 101):
	f[i] += f[i - 7]
while True:
	try:
		print(f[int(input())])
	except:
		break