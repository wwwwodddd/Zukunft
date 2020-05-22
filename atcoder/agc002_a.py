a, b = map(int, raw_input().split())
if a <= 0 and 0 <= b:
	print 'Zero'
elif a > 0 or (b - a) % 2 == 1:
	print 'Positive'
else:
	print 'Negative'