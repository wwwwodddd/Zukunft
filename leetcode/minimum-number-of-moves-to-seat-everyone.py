class Solution:
    def minMovesToSeat(self, a: List[int], b: List[int]) -> int:
        a.sort()
        b.sort()
        return sum(abs(a[i]-b[i])for i in range(len(a)))