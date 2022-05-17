class Solution:
    def countStudents(self, a: List[int], b: List[int]) -> int:
        c0 = a.count(0)
        c1 = a.count(1)
        for i in b:
            if i == 0:
                if c0:
                    c0 -= 1
                else:
                    break
            else:
                if c1:
                    c1 -= 1
                else:
                    break
        return c0 + c1