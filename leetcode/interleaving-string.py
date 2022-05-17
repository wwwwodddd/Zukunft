class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        f = [[False for j in range(len(s2)+1)]for i in range(len(s1)+1)]
        f[0][0] = True
        for i in range(len(s1)+1):
            for j in range(len(s2)+1):
                if f[i][j]:
                    if i<len(s1) and s1[i]==s3[i+j]:
                        f[i+1][j] = True
                    if j<len(s2) and s2[j]==s3[i+j]:
                        f[i][j+1] = True
        return f[len(s1)][len(s2)]