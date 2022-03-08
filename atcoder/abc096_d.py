def P(x):
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True
z = [i for i in range(11, 2000, 10) if P(i)]
print(*z[:int(input())])