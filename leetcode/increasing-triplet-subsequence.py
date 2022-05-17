class Solution:
    def increasingTriplet(self, a: List[int]) -> bool:
        x = 10**10
        y = 10**10
        z = 10**10
        for i in a:
            if i > y:
                z = min(z, i)
            if i > x:
                y = min(y, i)
            x = min(x, i)
        return z < 10**10