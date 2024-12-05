while True:
	a = list(map(int, input().split()))[1:]
	a.sort(key=abs, reverse=True)
	if a == []:
		break
	print(*a)