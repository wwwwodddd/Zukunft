import math
for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	for i in range(1, len(a) - 1):
		if math.gcd(math.lcm(a[i - 1], a[i]), math.lcm(a[i], a[i + 1])) != a[i]:
			print('NO')
			break
	else:
		print('YES')