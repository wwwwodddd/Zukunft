import sys
a = open('wordsort.in').read().split()
a.sort(key=lambda s:(-len(s), s))
sys.stdout = open('wordsort.out', 'w')
for i in a:
	print(i)