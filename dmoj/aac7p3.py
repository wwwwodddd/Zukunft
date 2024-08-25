# 枚举2个点 最短路 一定超时
# 两个点 (i, j) 之间的最短路有2种情况
# 1. i->j 直接走过去
# 2. i->离i最近的portal->离j最近的portal->j

# 肯定要把离每个点最近的portal求出来 O(n)
# 假设所有点对之间都用 第二种 方案
# 可以求出距离之和 O(n)

# 接下来考虑点对之间用第一种方案更好的情况 
# 每两个portal 分别处理

# 两个portal之间会有一些 checkpoints
# （这里当然也不能直接枚举2个checkpoints）
# 枚举其中一个点，另一个点分为2种情况

import sys
mod = 1000000007
n, m = map(int, sys.stdin.readline().split())
b = list(map(int, sys.stdin.readline().split()))
p = [0, 0] + list(map(int, sys.stdin.readline().split())) + [0]
f = [0 for i in range(n + 1)]
for i in range(1, n + 1):
	p[i] += p[i - 1]
p[0] = -2000000000
p[n + 1] = 2000000000
# print(p)
l = [0 for i in range(n + 2)]
r = [n + 1 for i in range(n + 2)]
for i in range(m):
	l[b[i]] = b[i]
	r[b[i]] = b[i]
for i in range(1, n + 1):
	if l[i] == 0:
		l[i] = l[i - 1]
for i in range(1, n + 1)[::-1]:
	if r[i] == n + 1:
		r[i] = r[i + 1]
for i in range(1, n + 1):
	f[i] = min(p[i] - p[l[i]], p[r[i]] - p[i])

z = 0
i = 1
j = 1
s = 0
t = sum(f)
while i <= n:
	while j <= n and p[j] - p[i] < f[j] + f[i]:
		t -= f[j]
		s += p[j]
		j += 1

	# 从 i 到 点i ~ j-1 直接走过去
	z = (z + s - p[i] * (j - i)) % mod
	# print(s, sum(p[i : j]))

	# 从 i 到 点 j~n 用portal
	z = (z + (n - j + 1) * f[i] + t) % mod
	# print(t, sum(f[j : n + 1]))

	s -= p[i]
	i += 1
print(z)