class Solution:
    def sumOfDigits(self, a: List[int]) -> int:
        return 1 - sum(int(i) for i in str(min(a))) % 2