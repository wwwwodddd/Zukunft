s = raw_input()
t = raw_input()
for i in range(len(s)):
	if s[i] != t[i]:
		if s[i] != '@' and t[i] != '@' or s[i] == '@' and t[i] not in 'atcoder' or t[i] == '@' and s[i] not in 'atcoder':
			print 'You will lose'
			break
else:
	print 'You can win'