class Solution:
    def judgeCircle(self, s: str) -> bool:
        return s.count('L')==s.count('R') and s.count('U')==s.count('D')