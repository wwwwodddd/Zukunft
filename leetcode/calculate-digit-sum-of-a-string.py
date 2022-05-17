class Solution:
    def digitSum(self, s: str, k: int) -> str:
        if len(s) <= k:
            return s
        t = ''
        for i in range(0, len(s), k):
            r = 0
            for j in s[i:i+k]:
                r += int(j)
            t += str(r)
        return self.digitSum(t, k)