for t in range(int(input())):
	print(['EVEN', 'ODD'][int(input()).bit_count() % 2])