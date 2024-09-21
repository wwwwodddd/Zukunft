n = int(input())
a = int(input())
b = int(input())
c = int(input())
z = 0
while n > 0:
	if n > 0:
		n -= 1
		a += 1
		z += 1
		if a % 35 == 0:
			n += 30
	if n > 0:
		n -= 1
		b += 1
		z += 1
		if b % 100 == 0:
			n += 60
	if n > 0:
		n -= 1
		c += 1
		z += 1
		if c % 10 == 0:
			n += 9
print('Martha plays', z, 'times before going broke.')