for t in range(int(input())):
	n = int(input())
	s = ''
	for i in range(5):
		s += 'aeiou'[i] * ((n + i) // 5)
	print(s)