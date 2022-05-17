class Solution:
    def wordCount(self, s: List[str], t: List[str]) -> int:
        a = set()
        for w in s:
            b = 0
            for l in w:
                b |= 1 << ord(l) - 97
            a.add(b)
        z = 0
        for w in t:
            b = 0
            for l in w:
                b |= 1 << ord(l) - 97
            for l in w:
                if b ^ 1 << ord(l) - 97 in a:
                    z += 1
                    break
        return z