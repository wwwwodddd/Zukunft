class Solution:
    def numOfBurgers(self, x: int, y: int) -> List[int]:
        if x % 2 == 1 or x < 2 * y or x > 4 * y:
            return []
        return [(x - 2 * y) // 2, (4 * y - x) // 2]