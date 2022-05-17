class Solution:
    def isPrefixOfWord(self, sentence: str, t: str) -> int:
        for i, s in enumerate(sentence.split()):
            if s.startswith(t):
                return i + 1
        return -1