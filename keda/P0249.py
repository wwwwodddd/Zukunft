s = input()
for e in ['er', 'ly', 'ing']:
	if s.endswith(e):
		s = s.removesuffix(e)
		break
print(s)