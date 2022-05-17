class Solution:
    def stringMatching(self, a: List[str]) -> List[str]:
        b=[]
        for i in a:
            for j in a:
                if i!=j and i in j:
                    b.append(i)
                    break
        return b