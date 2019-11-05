a = [7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, ]
print len(a)
ans = set([])
for n in range(2, 110):
	print n
	for i in range(2, 110):
		for j in range(1, 110):
			t = 10 ** n / i * j
			s = str(t)
			s = s[-1:] + s[:-1]
			r = int(s)
			if 10 < t and t < 10 ** 100 and r % t == 0:
#				print t
				ans.add(t)


for i in sorted(ans):
	print i
print sum(ans) % 10 ** 5
