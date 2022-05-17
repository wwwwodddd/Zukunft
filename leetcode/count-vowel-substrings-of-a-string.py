class Solution:
    def countVowelSubstrings(self, s: str) -> int:
        z = 0
        for i in range(len(s)):
            b = 0
            for j in range(i, len(s)):
                if s[j] in 'aeiou':
                    b |= 1 << 'aeiou'.index(s[j])
                    if b == 31:
                        z += 1
                else:
                    break
        return z