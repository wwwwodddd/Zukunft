class Solution:
    def find132pattern(self, a: List[int]) -> bool:
        s = []
        t = -10**10
        for i in a[::-1]:
            if i < t:
                return True
            while s and s[-1] < i:
                t = s.pop()
            s.append(i)
        return False