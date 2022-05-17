class Solution:
    def maxNumberOfBalloons(self, s: str) -> int:
        a = Counter(s)
        b = Counter('balloon')
        return min(a[i]//b[i]for i in b)