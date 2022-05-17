class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        z = 0
        for i in costs:
            if coins >= i:
                coins -= i
                z += 1
        return z
