class Solution:
    def combinationSum4(self, a: List[int], s: int) -> int:
        f = [0 for i in range(s+1)]
        f[0]=1
        for i in range(1,s+1):
            for j in a:
                if i>=j:
                    f[i]+=f[i-j]
        return f[s]