from collections import Counter
import sys
for i in sys.stdin.readlines():
	c = Counter(i.strip())
	if sum(c[j]%2 for j in c) > 1:
		print(-1)
	else:
		print(1)
