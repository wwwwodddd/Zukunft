class Solution:
    def findBuildings(self, a: List[int]) -> List[int]:
        z = []
        s = []
        for i in range(len(a)):
            while len(s) and a[i] >= a[s[-1]]:
                s.pop()
            s.append(i)
        return s