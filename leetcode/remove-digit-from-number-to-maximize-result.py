class Solution:
    def removeDigit(self, a: str, d: str) -> str:
        z = 0
        for i in range(len(a)):
            if a[i] == d:
                z = max(z, int(a[:i] + a[i+1:]))
        return str(z)