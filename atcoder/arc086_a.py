n, k = map(int, input().split())
g = {}
for i in input().split():
    if i not in g:
        g[i] = 0
    g[i] += 1
print(sum(sorted(g.values())[:-k]))