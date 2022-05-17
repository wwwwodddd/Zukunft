class Solution:
    def buddyStrings(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        if s==t:
            c=Counter(s)
            for i in c:
                if c[i]>1:
                    return True
            return False
        d=[(i,j)for i,j in zip(s,t)if i!=j]
        return len(d)==2 and d[0][0]==d[1][1] and d[0][1]==d[1][0]