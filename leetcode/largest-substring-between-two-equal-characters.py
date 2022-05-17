class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        return max(s.rfind(i)-s.find(i)-1 for i in set(s))