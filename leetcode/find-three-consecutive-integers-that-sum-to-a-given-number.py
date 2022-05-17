class Solution:
    def sumOfThree(self, n: int) -> List[int]:
        if n % 3:
            return []
        else:
            n //= 3
            return [n - 1, n, n + 1]