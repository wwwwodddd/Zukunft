class Solution:
    def camelMatch(self, queries: List[str], t: str) -> List[bool]:
        def cuo(s, t):
            j = 0
            for i in s:
                if j < len(t) and t[j] == i:
                    j += 1
                elif i.isupper():
                    return False
            return j == len(t)
        return [cuo(s, t) for s in queries]