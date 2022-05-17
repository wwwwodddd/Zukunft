class Solution:
    def sortJumbled(self, g: List[int], a: List[int]) -> List[int]:
        def cao(n):
            n = str(n)
            s = 0
            for i in n:
                s = s * 10 + g[int(i)]
            return s
        return sorted(a, key=cao)