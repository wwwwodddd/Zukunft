for t in range(int(input())):
	print(['Janmansh', 'Jay'][sum(map(int, input().split())) % 2])