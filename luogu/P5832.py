import sys
n = input()
s = raw_input()
for l in range(1, n + 1):
	if len(set([s[i:i+l] for i in range(n - l + 1)])) == n - l + 1:
		print l
		break