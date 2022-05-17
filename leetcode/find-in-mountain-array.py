# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, t: int, a: 'MountainArray') -> int:
        L = 0
        R = a.length() - 1
        while L < R - 1:
            M = (L + R) // 2
            if a.get(M) < a.get(M + 1):
                L = M
            else:
                R = M
        P = R
        L = -1
        R = P + 1
        while L < R - 1:
            M = (L + R) // 2
            u = a.get(M)
            if u == t:
                return M
            if u < t:
                L = M
            else:
                R = M
        L = P - 1
        R = a.length()
        while L < R - 1:
            M = (L + R) // 2
            u = a.get(M)
            if u == t:
                return M
            if u > t:
                L = M
            else:
                R = M
        return -1