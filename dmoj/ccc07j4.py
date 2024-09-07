import collections
s = collections.Counter(input().replace(' ', ''))
t = collections.Counter(input().replace(' ', ''))
if s == t:
	print('Is an anagram.')
else:
	print('Is not an anagram.')