def F(x, y):
	re = 0
	for i in range(1, 17):
		re += x * y ** (i - 1)
	return re

ans = 0
ans += F(15, 16) # +A01
#print F(15, 16)
ans -= F(14, 15) # -01
ans -= F(15, 15) # -A1
ans -= F(14, 15) # -A0
ans += F(14, 14) # +A
ans += F(14, 14) # +1
ans += F(13, 14) # +0
ans -= F(13, 13) # -
print ans
print '%X' % ans