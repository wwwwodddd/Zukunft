for t in range(int(input())):
	w, p, k = map(int, input().split())
	if w >= k:
		print(k * 2)
	else:
		print(w + k)