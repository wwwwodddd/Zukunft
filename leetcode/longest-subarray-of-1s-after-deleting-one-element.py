class Solution:
    def longestSubarray(self, a: List[int]) -> int:
        i = 0
        j = 0
        c = 0
        z = 0
        while True:
            while c > 1:
                if a[j] == 0:
                    c -= 1
                j += 1
            z = max(z, i - j)
            if i == len(a):
                break
            if a[i] == 0:
                c += 1
            i += 1
        return z - 1