class Solution:
    def kidsWithCandies(self, a: List[int], k: int) -> List[bool]:
        return [i+k>=max(a)for i in a]