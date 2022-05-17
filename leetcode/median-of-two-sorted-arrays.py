class Solution:
    def findMedianSortedArrays(self, a: List[int], b: List[int]) -> float:
        def cao(a, b, k):
            i = 0
            j = 0
            while k:
                if k & 1:
                    if j == len(b) or i < len(a) and a[i] < b[j]:
                        i += 1
                    else:
                        j += 1
                    k -= 1
                t = k // 2
                if j + t >= len(b) or i + t < len(a) and a[i + t] < b[j + t]:
                    i += t
                else:
                    j += t
                k -= t
            if j == len(b) or i < len(a) and a[i] < b[j]:
                return a[i]
            else:
                return b[j]
        return (cao(a, b, (len(a) + len(b)) // 2) + cao(a, b, (len(a) + len(b) - 1) // 2)) / 2