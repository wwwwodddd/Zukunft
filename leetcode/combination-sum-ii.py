class Solution:
    def combinationSum2(self, a: List[int], s: int) -> List[List[int]]:
        b = [0 for i in range(51)]
        for i in a:
            b[i] += 1
        f = [[] for i in range(s + 1)]
        f[0].append([])
        for i in range(51):
            for j in range(s+1)[::-1]:
                for k in range(1,b[i]+1):
                    if j-i*k>=0:
                        for t in f[j-i*k]:
                            f[j].append(t+[i]*k)
        return f[s]