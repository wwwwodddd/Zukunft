class Solution:
    def findOriginalArray(self, a: List[int]) -> List[int]:
        c=Counter(a)
        z=[]
        for i in sorted(a):
            while c[i]:
                z.append(i)
                c[i]-=1
                if c[2*i]:
                    c[2*i]-=1
                else:
                    return []
        return z