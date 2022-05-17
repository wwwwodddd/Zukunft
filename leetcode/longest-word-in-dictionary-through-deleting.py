class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        z=''
        for t in d:
            j=0
            for i in s:
                if j<len(t) and t[j]==i:
                    j+=1
            if j==len(t):
                if len(z)<len(t)or len(z)==len(t) and z>t:
                    z=t
        return z