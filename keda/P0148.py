n, m = map(int, input().split())
an = abs(n)
am = abs(m)
f0 = an // am
f1 = an % am
if n < 0:
	f0 = -f0
	f1 = -f1
if m < 0:
	f0 = -f0
print(f0, f1)