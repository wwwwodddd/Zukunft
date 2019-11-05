A = '1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679'
B = '8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196'
#print len(A), len(B)

#A = '1415926535'
#B = '8979323846'

def F(n):
	n -= 1
	l = [len(A), len(B)]
	for i in range(100):
		l.append(l[-1] + l[-2])
	for i in range(100):
		if n < l[i]:
			x = i
			y = n
			break
	while True:
		if x < 2:
#			print y
			if x == 0:
				return A[y]
			else:
				return B[y]
		if y < l[x - 2]:
			x -= 2
		else:
			y -= l[x - 2]
			x -= 1

#print F(35)
#	print n
ans = 0
for i in range(18):
	ans += 10 ** i * int(F((127 + 19 * i) * 7 ** i))

#print F(202)
#for i in range(1, 200):
#	print i, F(i)
print ans