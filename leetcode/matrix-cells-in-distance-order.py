class Solution:
    def allCellsDistOrder(self, n: int, m: int, x: int, y: int) -> List[List[int]]:
        return sorted([[i,j]for i in range(n)for j in range(m)],key=lambda a:abs(a[0]-x)+abs(a[1]-y))