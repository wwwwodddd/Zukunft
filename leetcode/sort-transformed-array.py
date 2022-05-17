class Solution:
    def sortTransformedArray(self, d: List[int], a: int, b: int, c: int) -> List[int]:
        return sorted(a * i * i + b * i + c for i in d)