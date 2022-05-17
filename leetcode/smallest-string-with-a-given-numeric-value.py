class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        k -= n
        s = ''
        while k > 25:
            k -= 25
            s += 'z'
        s += chr(97 + k)
        while len(s) < n:
            s += 'a'
        return s[::-1]