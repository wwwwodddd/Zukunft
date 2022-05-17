class Solution:
    def numSub(self, s: str) -> int:
        z = 0
        c = 0
        for i in s:
            if i == '1':
                c += 1
                z = (z + c) % 1000000007
            else:
                c = 0
        return z