class Solution:
    def minimumAbsDifference(self, a: List[int]) -> List[List[int]]:
        a.sort()
        d = 9**9
        z = []
        for i in range(1, len(a)):
            if d > a[i] - a[i-1]:
                d = a[i] - a[i-1]
                z = []
            if d == a[i] - a[i-1]:
                z.append((a[i-1], a[i]))
        return z