n = 3 ** 37 + 1

def G(n):
	ans = 0
	for i in range(1, n):
		ans += eval('0b' + bin(i)[2:][::-1])
	return ans

def F(n):

	first = True
	most = -1
	ans = 0
	for i in range(64)[::-1]:
		if n >> i & 1:
			if first:
				for j in range(1, i + 1):
					ans += 2 ** (j - 1)
					ans += (2 ** (j - 1) - 1) * (2 ** (j - 1))
				first = False
				most = i;
				ans += n % 2 ** i
#				print '?', ans
			else:
				if i > 0:
					ans += 2 ** (i - 1) * (2 ** i - 1) * 2 ** (most - i + 1)
#				print '!', ans
				ans += n % 2 ** i * 2 ** (most - i)
#				print '~', ans

	return ans

#print G(n)
print F(n) % 10 ** 9