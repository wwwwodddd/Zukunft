class Solution:
    def singleNumber(self, a: List[int]) -> List[int]:
        x = 0
        y = 0
        z = 0
        for i in a:
            z ^= i
        z &= -z
        for i in a:
            if i & z:
                x ^= i
            else:
                y ^= i
        return (x, y)