class Solution:
    def interpret(self, s: str) -> str:
        return s.replace('()','o').replace('(al)','al')