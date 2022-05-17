class Solution:
    def minDeletion(self, a: List[int]) -> int:
        b = []
        for i in a:
            if len(b) & 1 and b[-1] == i:
                b.pop()
            b.append(i)
        if len(b) & 1:
            b.pop()
        return len(a) - len(b)