def P(x):
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True
for t in range(int(input())):
	s = sum(map(int, input().split()))
	d = 1
	while not P(s + d):
		d += 1
	print(d)
