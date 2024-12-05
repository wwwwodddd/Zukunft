s = input()
t = ''
for i in s:
	if i in '018':
		t += i
	elif i in '69':
		t += str(15 - int(i))
	else:
		print('false')
		break
else:
	if s == t[::-1]:
		print('true')
	else:
		print('false')
