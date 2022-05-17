class Solution:
    def canConstruct(self, a: str, b: str) -> bool:
        a = Counter(a)
        b = Counter(b)
        for i in a:
            if a[i] > b[i]:
                return False
        return True