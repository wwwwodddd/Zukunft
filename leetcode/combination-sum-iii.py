class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        f = [[]for i in range(n + 1)]
        f[0].append([])
        for i in range(1,10):
            for j in range(i,n+1)[::-1]:
                for a in f[j-i]:
                    f[j].append(a+[i])
        return [a for a in f[n] if len(a)==k]