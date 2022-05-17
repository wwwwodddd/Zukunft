class Solution:
    def subsetsWithDup(self, a: List[int]) -> List[List[int]]:
        b=set()
        a=sorted(a)
        for i in range(2**len(a)):
            c=[]
            for j in range(len(a)):
                if i>>j&1:
                    c.append(a[j])
            b.add(tuple(c))
        return list(b)