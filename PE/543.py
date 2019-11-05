from sage.all import *
def F(n):
	if n == 2:
		return 1
	if n == 3:
		return 2
	z = 0
	if n >= 1:
		z += prime_pi(n)
	if n >= 2:
		z += n / 2 - 2 + prime_pi(n - 2)
	if n >= 3:
		z += (n - 5 + (n - 5) % 2) * ((n - 3) / 2) / 2
	return z 

print F(2)
print F(3)
print F(5)
print F(10)
print F(100)
print F(1000)
#exit()
f = [0, 1]
while len(f) < 45:
	f.append(f[-1] + f[-2])
s = 0
for i in range(3, 45):
	s += F(f[i])
print s