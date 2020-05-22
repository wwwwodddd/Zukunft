n = input()
t = map(int, raw_input().split())
v = map(int, raw_input().split())
t = [2 * i for i in t]
v = [2 * i for i in v]
f = [1000 for i in range(sum(t) + 1)]

s = 0
for i in range(n):
	for j in range(s, s + t[i] + 1):
		f[j] = min(f[j], v[i])
	s += t[i]
f[0] = 0
f[s] = 0

for i in range(1, s + 1):
	f[i] = min(f[i], f[i - 1] + 1)

for i in range(s)[::-1]:
	f[i] = min(f[i], f[i + 1] + 1)

print (sum(f[:-1]) + sum(f[1:])) / 8.0