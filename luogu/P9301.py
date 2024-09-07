n = int(input())
z = [0, 0, 0, 0, 0]
for i in range(n):
	s = input()
	for j in range(5):
		if s[j] == 'Y':
			z[j] += 1
a = [i+1 for i in range(5) if z[i] == max(z)]
print(','.join(map(str, a)))
