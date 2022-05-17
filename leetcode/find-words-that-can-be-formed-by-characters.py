class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        c = Counter(chars)
        z = 0
        for word in words:
            s = Counter(word)
            for i in s:
                if s[i] > c[i]:
                    break
            else:
                z += len(word)
        return z