class Solution:
    def fairCandySwap(self, a: List[int], b: List[int]) -> List[int]:
        d = sum(a) - sum(b)
        a = set(a)
        b = set(b)
        for i in a:
            if (2*i-d)//2 in b:
                return (i, (2*i-d)//2)