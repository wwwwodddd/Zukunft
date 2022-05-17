class Solution:
    def findRotation(self, a: List[List[int]], b: List[List[int]]) -> bool:
        for i in range(4):
            if a == b:
                return True
            a = list(map(list,zip(*a)))[::-1]
        return False