class Solution:
    def checkIfExist(self, a: List[int]) -> bool:
        if a.count(0) > 1:
            return True
        a = set(a)
        for i in a:
            if i and 2 * i in a:
                return True
        return False