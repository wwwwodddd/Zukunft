class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def zuo(s):
            z = 0
            for i in s:
                z = z * 10 + ord(i) - 97
            return z
        return zuo(firstWord) + zuo(secondWord) == zuo(targetWord)