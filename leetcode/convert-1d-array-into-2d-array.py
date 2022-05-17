class Solution:
    def construct2DArray(self, a: List[int], m: int, n: int) -> List[List[int]]:
        if len(a) != m * n:
            return []
        return [a[i*n:i*n+n]for i in range(m)]