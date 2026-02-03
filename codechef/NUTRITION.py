for t in range(int(input())):
	n = int(input())
	s = [0 for i in range(101)]
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	for i in range(n):
		s[a[i]] = max(s[a[i]], b[i])
	print(sum(s))