class Solution:
    def findKthLargest(self, a: List[int], k: int) -> int:
        return sorted(a)[-k]