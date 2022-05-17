class Solution:
    def countBattleships(self, s: List[List[str]]) -> int:
        z = 0
        for i in range(len(s)):
            for j in range(len(s[i])):
                if s[i][j] == 'X' and (i == 0 or s[i-1][j] != 'X') and (j == 0 or s[i][j-1] != 'X'):
                    z += 1
        return z