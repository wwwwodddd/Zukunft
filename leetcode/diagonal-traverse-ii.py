class Solution:
    def findDiagonalOrder(self, a: List[List[int]]) -> List[int]:
        b = []
        for i in range(len(a)):
            for j in range(len(a[i])):
                b.append((i+j,j,a[i][j]))
        b.sort()
        return [i[2]for i in b]