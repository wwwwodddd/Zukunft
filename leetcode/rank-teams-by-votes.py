class Solution:
    def rankTeams(self, b: List[str]) -> str:
        g = {i:[0 for j in range(26)] + [i] for i in b[0]}
        for a in b:
            for i in range(len(a)):
                g[a[i]][i] -= 1
        return ''.join(i[-1] for i in sorted(g.values()))