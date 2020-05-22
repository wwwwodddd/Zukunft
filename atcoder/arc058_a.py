n, k = map(int, raw_input().split())
a = set(raw_input().split())
while set(str(n)) & a:
	n += 1
print n