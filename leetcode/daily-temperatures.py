class Solution:
    def dailyTemperatures(self, a: List[int]) -> List[int]:
        n = len(a)
        s = []
        z = [0 for i in range(n)]
        for i in range(n):
            while len(s) and a[s[-1]] < a[i]:
                z[s[-1]] = i - s[-1]
                s.pop()
            s.append(i)
        return z