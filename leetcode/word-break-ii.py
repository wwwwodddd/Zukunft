class Solution:
    def wordBreak(self, s: str, w: List[str]) -> List[str]:
        n = len(s)
        f = [[] for i in range(n + 1)]
        f[0].append([])
        w = set(w)
        for i in range(1, n + 1):
            for j in range(i)[::-1]:
                if s[j:i] in w:
                    for k in f[j]:
                        f[i].append(k + [s[j:i]])
        return [' '.join(i) for i in f[n]]