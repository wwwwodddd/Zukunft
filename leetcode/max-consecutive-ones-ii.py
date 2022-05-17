class Solution:
    def findMaxConsecutiveOnes(self, a: List[int]) -> int:
        j = 0
        c = 0
        z = 0
        for i in range(len(a)):
            if a[i] == 0:
                c += 1
            while c > 1:
                if a[j] == 0:
                    c -= 1
                j += 1
            z = max(z, i - j + 1)
        return z