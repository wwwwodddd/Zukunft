for t in range(int(input())):
	n, m = map(int, input().split())
	if n <= m and m <= n * 3 and (m - n) % 2 == 0:
		print("YES")
	else:
		print("NO")