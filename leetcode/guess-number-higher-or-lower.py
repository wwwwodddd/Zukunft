# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        l=1
        r=n
        while l<=r:
            m=(l+r)//2
            t=guess(m)
            if t==0:
                return m
            if t<0:
                r=m-1
            if t>0:
                l=m+1
                