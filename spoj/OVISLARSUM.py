p = 1000000007
l, r, mod = map(int, input().split())
def S(l, r):
	return (r + l) * (r - l + 1) // 2
if l // mod == r // mod:
	z = S(l % mod, r % mod)
else:
	z = S(l % mod, mod - 1) + S(0, mod - 1) * (r // mod - l // mod - 1) + S(0, r % mod)
print(z % p)