class Solution:
    def destCity(self, p: List[List[str]]) -> str:
        a, b = zip(*p)
        return (set(b)-set(a)).pop()