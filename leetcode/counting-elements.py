class Solution:
    def countElements(self, a: List[int]) -> int:
        s = set(a)
        z = 0
        for i in a:
            if i + 1 in s:
                z += 1
        return z