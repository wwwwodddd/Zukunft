class Solution:
    def findDiagonalOrder(self, a: List[List[int]]) -> List[int]:
        b = [(i+j,[j,i][(i+j)%2],a[i][j])for i in range(len(a))for j in range(len(a[0]))]
        b.sort()
        return [i[-1]for i in b]