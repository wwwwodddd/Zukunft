class Solution:
    def killProcess(self, pid: List[int], f: List[int], kill: int) -> List[int]:
        g = {}
        for i in range(len(pid)):
            g[pid[i]] = i
        for i in range(len(f)):
            if f[i] == 0:
                f[i] = -1
            else:
                f[i] = g[f[i]]
        kill = g[kill]
        def F(x):
            if x == -1:
                return -1
            if x == kill:
                return kill
            f[x] = F(f[x])
            return f[x]
        z = []
        for i in range(len(pid)):
            if F(i) == kill:
                z.append(pid[i])
        return z