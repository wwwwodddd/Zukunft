class Solution:
    def maxProfit(self, a: List[int]) -> int:
        b = bsb = -9**9
        bs = bsbs = 0
        for i in a:
            bsbs = max(bsbs, bsb+i)
            bsb = max(bsb, bs-i)
            bs = max(bs, b+i)
            b = max(b, -i)
        return bsbs