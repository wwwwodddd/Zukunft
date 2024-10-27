n, t = map(int, input().split())
a = list(map(int, input().split()))
L = 0
R = 10 ** 18
while L < R - 1:
	M = (L + R) // 2
	s = sum(M // i for i in a)
	if s < t:
		L = M
	else:
		R = M
print(R)