def f(n, k):
	n -= k * (k - 1) / 2
	return max(n / k, 0)
def F(n):
	k = 1
	re = 0
	while k * (k - 1) / 2 <= n:
		re += f(n, k)
		k += 1
	return re
def S(n):
	ans = 0
	for i in range(1, n + 1):
		ans += F(i)
	return ans
def SS(n):
	n += 1
	k = 1
	re = 0
	while k * (k - 1) / 2 <= n:
		m = (n - k * (k - 1) / 2) / k
		re += m * (m - 1) / 2 * k + ((n - k * (k - 1) / 2)) % k * m
		k += 1
	return re
n = 10000
print S(n)
print SS(n)
print SS(10 ** 16)
