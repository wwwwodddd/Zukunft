s = 'thereisasyetinsufficientdataforameaningfulanswer'
d = {}
for i in s:
	if i not in d:
		d[i] = 1
	else:
		d[i] += 1
f = [{} for i in range(16)]
def F(a, l):
	if a in f[l]:
		return f[l][a]
	re = 1
	if l == 0:
		return re
	for i in range(len(a)):
		if a[i] > 0:
			b = a[:i] + tuple([a[i] - 1]) + a[i + 1:]
			b = tuple(sorted(b))
			re += F(b, l - 1)
	f[l][a] = re
	return re

def P(s):
	re = 0
	dd = d.copy()
	for i in range(len(s)):
		re += 1
		for j in sorted(dd.keys()):
			if j < s[i] and dd[j] > 0:
				dd[j] -= 1
				re += F(tuple(sorted(dd.values())), 14 - i)
				dd[j] += 1
		dd[s[i]] -= 1
	return re

def W(n):
	re = ''
	dd = d.copy()
	for i in range(15):
		if n > 0:
			n -= 1
			for j in sorted(dd.keys()):
				if dd[j] > 0:
					dd[j] -= 1
					t = F(tuple(sorted(dd.values())), 14 - i)
					if n >= t:
						n -= t
					else:
						re += j
						break
					dd[j] += 1
		else:
			break
	return re

#print W(115246685191495243)
print W(P('legionary') + P('calorimeters') - P('annihilate') + P('orchestrated') - P('fluttering'))
#print F(tuple(a), 15)
#print 525069350231428029