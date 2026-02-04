s = input() + input() + input() + input()
for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
	print(i + '*' * s.count(i))