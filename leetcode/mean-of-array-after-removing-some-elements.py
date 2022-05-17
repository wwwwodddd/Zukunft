class Solution:
    def trimMean(self, a: List[int]) -> float:
        a.sort()
        a = a[len(a)//20:-len(a)//20]
        return sum(a)/len(a)
        