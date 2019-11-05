'''
import fractions
import itertools

limit = 10
s = [set([]) for i in range(2 ** limit)]
for i in range(1, 2 ** limit):
	j = i
	c = [i >> j & 1 for j in range(limit)]
	digits = list(itertools.compress(range(limit), c))
#	print digits
#	exit()
	for num in itertools.permutations(digits):
		s[i].add(fractions.Fraction(''.join(map(str, num))))
	while True:
		j = (j - 1) & i
		if j == 0:
			break
		for fst in s[j]:
			for snd in s[i ^ j]:
				s[i].add(fst + snd)
				s[i].add(fst - snd)
				s[i].add(fst * snd)
				if snd != 0:
					s[i].add(fst / snd)

zhenshiyouqu = 0
for i in s[2 ** limit - 1]:
	if i > 0 and i.denominator == 1:
		zhenshiyouqu += i
print zhenshiyouqu


'''

import fractions
import itertools

limit = 10
s = [[set([]) for i in range(limit)] for j in range(limit)]

for length in range(limit):
	for i in range(1, limit - length):
		x = 0
		for k in range(i, i + length + 1):
			x = 10 * x + k
		s[i][i + length].add(fractions.Fraction(x))
		for k in range(i, i + length):
			for fst in s[i][k]:
				for snd in s[k + 1][i + length]:
					s[i][i + length].add(fst + snd)
					s[i][i + length].add(fst - snd)
					s[i][i + length].add(fst * snd)
					if snd != 0:
						s[i][i + length].add(fst / snd)

zhenshiyouqu = 0
for i in s[1][limit - 1]:
#for i in s[2][3]:
	if i > 0 and i.denominator == 1:
		zhenshiyouqu += i
#		print i
print zhenshiyouqu