import math
ans = 0
for i in range(1, 2012):
	for j in range(i + 1, 2012 - i):
		k = i + j - 2 * ((i * j) ** 0.5)
		if k >= 1:
			continue
		print k
		ans += int(math.ceil((-2011 * math.log(10)) / math.log(k)))

print ans
