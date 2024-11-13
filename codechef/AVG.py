for t in range(int(input())):
	n, k, v = map(int, input().split())
	s = v * (n + k) - sum(map(int, input().split()))
	if s % k == 0 and s // k > 0:
		print(s // k)
	else:
		print(-1)