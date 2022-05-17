class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        a = [0, 0, 0]
        z = len(s) * (len(s) + 1) // 2
        j = 0
        for i in range(len(s)):
            a[ord(s[i]) - 97] += 1
            while a[0] and a[1] and a[2]:
                a[ord(s[j]) - 97] -= 1
                j += 1
            z -= i - j + 1
        return z