n, m = map(int, input().split())
s = 0
z = 0
for i in range(n):
	t = sum(map(int, input().split()))
	if s < t:
		s = t
		z = i
print(z + 1)