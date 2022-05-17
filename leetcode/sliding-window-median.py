import sortedcontainers
class Solution:
    def medianSlidingWindow(self, a: List[int], k: int) -> List[float]:
        s = sortedcontainers.SortedList()
        z = []
        for i in range(len(a)):
            s.add(a[i])
            if i >= k - 1:
                z.append((s[k//2]+s[(k-1)//2])/2)
                s.remove(a[i - k + 1])
        return z