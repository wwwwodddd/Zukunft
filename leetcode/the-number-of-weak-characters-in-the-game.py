class Solution:
    def numberOfWeakCharacters(self, a: List[List[int]]) -> int:
        a.sort(key=lambda x:(-x[0],x[1]))
        c = 0
        my = 0
        for x, y in a:
            if my > y:
                c += 1
            else:
                my = y
        return c