class Solution:
    def removeOnes(self, a: List[List[int]]) -> bool:
        n = len(a)
        m = len(a[0])
        for i in range(n):
            for j in range(m):
                if a[i][j] ^ a[i][0] ^ a[0][j] ^ a[0][0]:
                    return False
        return True