class Solution:
    def validSubarrays(self, a: List[int]) -> int:
        s = []
        a += [-1]
        z = 0
        for i in range(len(a)):
            while s and a[i] < a[s[-1]]:
                z += i - s.pop()
            s.append(i)
        return z