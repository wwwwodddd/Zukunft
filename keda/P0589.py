s, t = input().split()
if len(s) > len(t):
	s, t = t, s
if s in t + t:
	print('true')
else:
	print('false')