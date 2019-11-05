p = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

n = len(p)
limit = 10 ** 13
cnt = 0
def F(x):
	if x == 0:
		return -1
	u = 0
	for i in p:
		if x % i == 0:
			u += 1
			while x % i == 0:
				x /= i
	if x > 1:
		return -1
	else:
		return u

ans = 0
def dfs(x, y, z):
	global cnt, ans
	if z > 7:
		return
	if y == n:
		t1 = F(x + 1)
		if t1 != -1:
#			print x
			ans += x
			cnt += 1
		t2 = F(x - 1)
		if t2 != -1 and t2 > 7:
#			print x - 1
			ans += x - 1
			cnt += 1
#		print x
		return
	u = 0
	while x <= limit:
		dfs(x, y + 1, z + u)
		x *= p[y]
		u = 1

#print F(4)
#exit()
dfs(1, 0, 0)
print cnt
print ans
