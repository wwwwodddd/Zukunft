class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        n = len(s)
        f = [[]for i in range(n+1)]
        f[n] = [-1] * 26
        for i in range(n)[::-1]:
            f[i] = f[i + 1][:]
            f[i][ord(s[i]) - 97] = i
        def subseq(t):
            j = 0
            for i in t:
                j = f[j][ord(i) - 97] + 1
                if j == 0:
                    return False
            return True
        return sum(subseq(w)for w in words)