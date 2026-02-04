for t in range(int(input())):
	n, k = map(int, input().split())
	s = input().rstrip('0')
	print(s.count('1') + min(s.count('0', k)))