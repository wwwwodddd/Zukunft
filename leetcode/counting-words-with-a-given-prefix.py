class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(i.startswith(pref)for i in words)
        