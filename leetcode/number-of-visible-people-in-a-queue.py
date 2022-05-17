class Solution:
    def canSeePersonsCount(self, h: List[int]) -> List[int]:
        s = []
        z = []
        for i in h[::-1]:
            t = 0
            while len(s) > 0 and s[-1] < i:
                s.pop()
                t += 1
            if len(s) > 0:
                t += 1
            s.append(i)
            z.append(t)
        return z[::-1]