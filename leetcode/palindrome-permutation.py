class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        c = Counter(s)
        z = 0
        for i in c:
            z += c[i] % 2
        return z <= 1