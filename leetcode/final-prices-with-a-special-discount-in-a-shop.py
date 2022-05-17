class Solution:
    def finalPrices(self, a: List[int]) -> List[int]:
        s = []
        for i in range(len(a)):
            while len(s) and a[s[-1]] >= a[i]:
                a[s[-1]] -= a[i]
                s.pop()
            s.append(i)
        return a