s = input()
t = input()
for i in range(len(t)):
	if t[i:] + t[:i] in s:
		print('yes')
		break
else:
	print('no')