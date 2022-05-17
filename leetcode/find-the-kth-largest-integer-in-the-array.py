class Solution:
    def kthLargestNumber(self, a: List[str], k: int) -> str:
        return sorted(a,key=int)[-k]