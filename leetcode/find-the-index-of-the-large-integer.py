# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader(object):
#	 # Compares the sum of arr[l..r] with the sum of arr[x..y]
#	 # return 1 if sum(arr[l..r]) > sum(arr[x..y])
#	 # return 0 if sum(arr[l..r]) == sum(arr[x..y])
#	 # return -1 if sum(arr[l..r]) < sum(arr[x..y])
#    def compareSub(self, l: int, r: int, x: int, y: int) -> int:
#
#	 # Returns the length of the array
#    def length(self) -> int:
#


class Solution:
    def getIndex(self, a: 'ArrayReader') -> int:
        L = 0
        R = a.length()
        while L < R - 1:
            D = (R - L + 1) // 3
            v = a.compareSub(L, L + D - 1, L + D, L + D + D - 1)
            if v == 0:
                L += 2 * D
            elif v > 0:
                R = L + D
            else:
                L += D
                R = L + D
        return L