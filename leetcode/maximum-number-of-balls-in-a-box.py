class Solution:
    def countBalls(self, l: int, h: int) -> int:
        d = [0 for i in range(99)]
        for i in range(l, h + 1):
            d[sum(map(int,str(i)))]+=1
        return max(d)