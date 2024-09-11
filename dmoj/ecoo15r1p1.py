from collections import Counter
while True:
	try:
		c = Counter()
		while True:
			s = input()
			if s == 'end of box':
				break
			c[s] += 1
		z = c['red'] * 16
		for i in c:
			if i != 'red':
				z += (c[i] + 6) // 7 * 13
		print(z)
	except:
		break