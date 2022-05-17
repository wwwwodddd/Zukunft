class Solution:
    def sortByBits(self, a: List[int]) -> List[int]:
        a.sort(key=lambda x:(bin(x).count('1'),x))
        return a