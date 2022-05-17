class Solution:
    def kClosest(self, a: List[List[int]], k: int) -> List[List[int]]:
        return sorted(a,key=lambda x:x[0]**2+x[1]**2)[:k]