for t in range(int(input())):
	n = int(input())
	r = int(n ** 0.5)
	s = input()
	if r == 1:
		t = '1'
	else:
		t = '1' * r + ('1' + '0' * (r - 2) + '1') * (r - 2) + '1' * r
	if s == t:
		print('Yes')
	else:
		print('No')