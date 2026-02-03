for i in range(int(input())):
	n = int(input())
	c = [0 for i in range(3)]
	for i in map(int, input().split()):
		c[i] += 1
	if n % 2 == 0 and c[1] <= n // 2 and c[2] <= n // 2:
		print("Yes")
	else:
		print("No")