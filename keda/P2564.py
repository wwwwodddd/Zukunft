t = int(input())

def F(a):
	if len(a) == 0:
		return True
	for i in range(n):
		b0 = []
		s0 = set()
		b1 = []
		s1 = set()
		for j in range(len(a)):
			if a[j][0][i] == '0':
				b0.append(a[j])
				s0.add(a[j][1])
			else:
				b1.append(a[j])
				s1.add(a[j][1])
		if len(b0) > 0 and len(s0) == 1:
			return F(b1)
		if len(b1) > 0 and len(s1) == 1:
			return F(b0)
	return False

for tt in range(t):
	input()
	n, m = map(int, input().split())
	a = []
	for i in range(m):
		a.append(input().split())
	if F(a):
		print('OK')
	else:
		print('LIE')