import fractions
n = int(input())
a = list(map(int, input().split()))
z = 0
for j in range(n):
	for i in range(j):
		if a[i] < a[j]:
			z += fractions.Fraction(a[i] - 1, 2 * a[j])
		else:
			z += 1 - fractions.Fraction(a[j] + 1, 2 * a[i])
print('%.6f' % z)