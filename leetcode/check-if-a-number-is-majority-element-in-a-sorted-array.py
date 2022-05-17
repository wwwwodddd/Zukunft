class Solution:
    def isMajorityElement(self, a: List[int], t: int) -> bool:
        return a.count(t) > len(a) // 2