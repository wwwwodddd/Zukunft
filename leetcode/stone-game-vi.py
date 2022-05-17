class Solution:
    def stoneGameVI(self, a: List[int], b: List[int]) -> int:
        c = sorted(zip(a, b), key=lambda x:-x[0]-x[1])
        x = sum(i[0] for i in c[0::2])
        y = sum(i[1] for i in c[1::2])
        if x > y:
            return 1
        elif x < y:
            return -1
        else:
            return 0