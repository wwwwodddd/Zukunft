for t in range(int(input())):
	a = input().split()
	b = input().split()
	for i in a:
		if i in b:
			print(i)
			break
