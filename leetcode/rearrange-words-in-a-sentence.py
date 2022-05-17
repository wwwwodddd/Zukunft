class Solution:
    def arrangeWords(self, t: str) -> str:
        return ' '.join(sorted(t.split(),key=len)).capitalize()