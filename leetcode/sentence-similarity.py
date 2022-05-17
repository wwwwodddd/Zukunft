class Solution:
    def areSentencesSimilar(self, a: List[str], b: List[str], p: List[List[str]]) -> bool:
        s = set()
        for x, y in p:
            s.add((x, y))
            s.add((y, x))
        if len(a) != len(b):
            return False
        for i in range(len(a)):
            if a[i] != b[i] and (a[i], b[i]) not in s:
                return False
        return True