for t in range(int(input())):
	n = int(input())
	if n % 2 == 1:
		s = 3
		e = n - 1
		a = [1]
		for i in range(n // 2):
			a.append(e)
			a.append(s)
			e -= 2
			s += 2
		print(*a)
	else:
		print(-1)
