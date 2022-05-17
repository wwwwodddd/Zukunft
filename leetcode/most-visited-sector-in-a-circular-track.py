class Solution:
    def mostVisited(self, n: int, a: List[int]) -> List[int]:
        if a[0] <= a[-1]:
            return list(range(a[0], a[-1] + 1))
        else:
            return list(range(1, a[-1] + 1)) + list(range(a[0], n + 1))