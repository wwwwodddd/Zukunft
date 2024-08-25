t = int(input())
for i in range(t):
	a, b, p = map(int, input().split())
	if a * b != p:
		print('16 BIT S/W ONLY')
	else:
		print('POSSIBLE DOUBLE SIGMA')
