class Solution:
    def removeKdigits(self, a: str, k: int) -> str:
        s = []
        for i in a:
            while len(s) > 0 and s[-1] > i and k > 0:
                s.pop()
                k -= 1
            s.append(i)
        while k:
            s.pop()
            k -= 1
        return str(int('0'+''.join(s)))