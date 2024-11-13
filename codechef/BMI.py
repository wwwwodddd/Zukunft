for t in range(int(input())):
	m, h = map(int, input().split())
	b = m // h // h
	if b <= 18:
		print(1)
	elif b <= 24:
		print(2)
	elif b <= 29:
		print(3)
	else:
		print(4)
