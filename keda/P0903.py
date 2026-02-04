input()
a = list(map(int, input().split()))
z = 0
s = 0
for i in a:
	s += i
	z = max(z, s)
print(z)
