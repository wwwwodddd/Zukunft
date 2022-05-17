class Solution:
    def countKDifference(self, a: List[int], k: int) -> int:
        c = Counter(i for i in a)
        return sum(c[i - k] for i in a)