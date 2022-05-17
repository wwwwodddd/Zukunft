class Solution:
    def findLonely(self, a: List[int]) -> List[int]:
        a.sort()
        a = [-9**9] + a + [9**9]
        z = []
        for i in range(1, len(a) - 1):
            if a[i-1] + 1 < a[i] < a[i+1] - 1:
                z.append(a[i])
        return z