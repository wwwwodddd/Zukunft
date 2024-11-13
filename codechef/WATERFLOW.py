for t in range(int(input())):
	w, x, y, z = map(int, input().split())
	if w + y * z < x:
		print('unfilled')
	elif w + y * z > x:
		print('overflow')
	else:
		print('filled')
