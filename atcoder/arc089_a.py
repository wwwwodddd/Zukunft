n = input()
tt, xx, yy = 0, 0, 0
for i in range(n):
	t, x, y = map(int, raw_input().split())
	d = abs(x - xx) + abs(y - yy)
	if d > t - tt or (d + t - tt) % 2 > 0:
		print 'No'
		exit()
	tt, xx, yy = t, x, y
print 'Yes'