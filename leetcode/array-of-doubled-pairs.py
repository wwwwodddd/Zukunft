class Solution:
    def canReorderDoubled(self, a: List[int]) -> bool:
        c = Counter(a)
        for i in sorted(c,key=abs):
            c[i*2]-=c[i]
            if c[i*2]<0:
                return False
        return True