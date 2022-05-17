class Solution:
    def canFormArray(self, a: List[int], p: List[List[int]]) -> bool:
        for b in p:
            if b[0] not in a or a[a.index(b[0]):a.index(b[0])+len(b)] != b:
                return False
        return True