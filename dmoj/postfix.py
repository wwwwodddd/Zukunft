a = input().split()
s = []
for i in a:
	if i == '+':
		y = s.pop()
		x = s.pop()
		s.append(x + y)
	elif i == '-':
		y = s.pop()
		x = s.pop()
		s.append(x - y)
	elif i == '*':
		y = s.pop()
		x = s.pop()
		s.append(x * y)
	elif i == '/':
		y = s.pop()
		x = s.pop()
		s.append(x / y)
	elif i == '%':
		y = s.pop()
		x = s.pop()
		s.append(x % y)
	elif i == '^':
		y = s.pop()
		x = s.pop()
		s.append(x ** y)
	else:
		s.append(float(i))
print(s[0])