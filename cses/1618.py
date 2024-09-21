n = int(input())
s = 0
while n > 0:
	n //= 5
	s += n
print(s)