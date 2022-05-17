class Solution:
    def mostWordsFound(self, a: List[str]) -> int:
        return max(len(s.split())for s in a)