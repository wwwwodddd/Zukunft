class Solution:
    def coinChange(self, a: List[int], m: int) -> int:
        f = [9**9 for i in range(m+1)]
        f[0] = 0
        for i in a:
            for j in range(i,m+1):
                f[j]=min(f[j],f[j-i]+1)
        if f[m]==9**9:
            f[m]=-1
        return f[m]