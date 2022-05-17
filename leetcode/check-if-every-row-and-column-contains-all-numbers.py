class Solution:
    def checkValid(self, a: List[List[int]]) -> bool:
        for i in a:
            if len(set(i)) != len(a):
                return False
        for i in zip(*a):
            if len(set(i)) != len(a):
                return False
        return True