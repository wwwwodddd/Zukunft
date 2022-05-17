class Solution:
    def calcEquation(self, e: List[List[str]], v: List[float], q: List[List[str]]) -> List[float]:
        a = defaultdict(list)
        for i in range(len(e)):
            a[e[i][0]].append((e[i][1], v[i]))
            a[e[i][1]].append((e[i][0], 1 / v[i]))
        z = defaultdict(lambda:-1)
        def dfs(s, x, d):
            nonlocal z
            if (s, x) in z:
                return
            z[(s, x)] = d
            for y, w in a[x]:
                dfs(s, y, d * w)
        for s in a:
            dfs(s, s, 1)
        return [z[tuple(i)]for i in q]