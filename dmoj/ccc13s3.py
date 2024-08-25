t = int(input())
g = int(input())
sc = [0, 0, 0, 0, 0]
r = [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]
for i in range(g):
	a, b, sa, sb = map(int, input().split())
	if sa > sb:
		sc[a] += 3
	elif sa < sb:
		sc[b] += 3
	else:
		sc[a] += 1
		sc[b] += 1
	r.remove([a, b])
z = 0
def dfs(i):
	global z
	if i == len(r):
		if sc[t] == max(sc) and sc.count(max(sc)) == 1:
			z += 1
		return
	a, b = r[i]
	sc[a] += 3
	dfs(i + 1)
	sc[a] -= 3
	sc[b] += 3
	dfs(i + 1)
	sc[b] -= 3
	sc[a] += 1
	sc[b] += 1
	dfs(i + 1)
	sc[a] -= 1
	sc[b] -= 1
dfs(0)
print(z)