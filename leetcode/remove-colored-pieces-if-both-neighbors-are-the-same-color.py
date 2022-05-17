class Solution:
    def winnerOfGame(self, s: str) -> bool:
        c=0
        for i,j,k in zip(s,s[1:],s[2:]):
            if i==j==k:
                if i=='A':
                    c+=1
                else:
                    c-=1
        return c>0