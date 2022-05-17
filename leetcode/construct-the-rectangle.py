class Solution:
    def constructRectangle(self, a: int) -> List[int]:
        z = i = 1
        while i * i <= a:
            if a % i == 0:
                z = i
            i += 1
        return [a // z, z]