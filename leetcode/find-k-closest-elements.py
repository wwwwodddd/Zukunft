class Solution:
    def findClosestElements(self, a: List[int], k: int, x: int) -> List[int]:
        a.sort(key=lambda y:(abs(x-y),y))
        return sorted(a[:k])