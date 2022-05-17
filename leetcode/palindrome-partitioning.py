class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n=len(s)
        f=[[] for i in range(n+1)]
        f[0].append([])
        for i in range(n):
            for j in range(i+1,n+1):
                if s[i:j]==s[i:j][::-1]:
                    for k in f[i]:
                        f[j].append(k+[s[i:j]])
        return f[n]