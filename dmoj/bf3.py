n = int(input())
def isPrime(n):
	if n < 2:
		return False
	i = 2
	while i * i <= n:
		if n % i == 0:
			return False
		i += 1
	return True
while not isPrime(n):
	n += 1
print(n)
