class Solution:
    def countValidWords(self, s: str) -> int:
        return sum(1 for i in s.split()if re.match('([a-z]+(-[a-z]+)?)?[!.,]?$', i))