import math
for t in range(int(input())):
	n, d, e = map(int, input().split())
	pplusq = n - d * e + 2
	pminusq2 = pplusq * pplusq - 4 * n
	if pminusq2 < 0 or pplusq < 0:
		print('NO')
	else:
		pminusq = math.isqrt(pminusq2)
		p = (pplusq - pminusq) // 2
		q = (pplusq + pminusq) // 2
		if p * q == n and e * d == (p - 1) * (q - 1) + 1:
			print(p, q)
		else:
			print('NO')