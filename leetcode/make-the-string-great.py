class Solution:
    def makeGood(self, s: str) -> str:
        z = []
        for i in s:
            if len(z) and (ord(z[-1])^ord(i)) == 32:
                z.pop()
            else:
                z.append(i)
        return ''.join(z)