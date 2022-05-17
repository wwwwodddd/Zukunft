class Solution:
    def getLucky(self, a: str, k: int) -> int:
        s = ''
        for i in a:
            s += str(ord(i) - 96)
        for i in range(k):
            t = 0
            for j in s:
                t += int(j)
            s = str(t)
        return s