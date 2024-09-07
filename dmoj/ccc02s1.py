a = int(input())
b = int(input())
c = int(input())
d = int(input())
n = int(input())
z = 0
w = 1e9
for i in range(0, (n // a) + 1):
	for j in range(0, (n - i * a) // b + 1):
		for k in range(0, (n - i * a - j * b) // c + 1):
			m = n - i * a - j * b - k * c
			if m % d == 0:
				z += 1
				w = min(w, i + j + k + m // d)
				print('# of PINK is', i, '# of GREEN is', j, '# of RED is', k, '# of ORANGE is', m // d)
print('Total combinations is %d.' % z)
print('Minimum number of tickets to print is %d.' % w)