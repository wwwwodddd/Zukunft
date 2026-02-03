def P(x1, y1, x2, y2):
	return ((x1-x2)**2 + (y1-y2)**2) <= r**2
for t in range(int(input())):
	r = int(input())
	a = [list(map(int, input().split())) for i in range(3)]
	if P(a[0][0], a[0][1], a[1][0], a[1][1]) + P(a[1][0], a[1][1], a[2][0], a[2][1]) + P(a[2][0], a[2][1], a[0][0], a[0][1]) >= 2:
		print("yes")
	else:
		print("no")