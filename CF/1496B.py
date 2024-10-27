for t in range(int(input())):
	n, k = map(int, input().split())
	a = set(map(int, input().split()))
	mx = max(a)
	me = 0
	for i in range(k):
		while me in a:
			me += 1
		if mx < me:
			print(me + k - i)
			break
		if (me + mx + 1) // 2 in a:
			print(len(a))
			break
		a.add((me + mx + 1) // 2)
	else:
		print(len(a))