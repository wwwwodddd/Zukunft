class Solution:
    def maximumEvenSplit(self, n: int) -> List[int]:
        if n & 1:
            return []
        a = []
        i = 2
        while n >= i:
            a.append(i)
            n -= i
            i += 2
        a[-1] += n
        return a