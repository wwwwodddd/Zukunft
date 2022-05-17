class Solution:
    def validWordSquare(self, a: List[str]) -> bool:
        for i in range(len(a)):
            for j in range(len(a[i])):
                if j >= len(a):
                    return False
                if i >= len(a[j]):
                    return False
                if a[i][j] != a[j][i]:
                    return False
        return True