class Solution:
    def average(self, a: List[int]) -> float:
        return (sum(a)-max(a)-min(a))/(len(a)-2)