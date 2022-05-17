class Solution:
    def divisorSubstrings(self, n: int, k: int) -> int:
        s = str(n)
        z = 0
        for i in range(k, len(s) + 1):
            if int(s[i - k: i]) > 0 and n % int(s[i - k: i]) == 0:
                z += 1
        return z