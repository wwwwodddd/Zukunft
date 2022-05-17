class Solution:
    def triangularSum(self, a: List[int]) -> int:
        for i in range(len(a))[::-1]:
            for j in range(i):
                a[j] = (a[j] + a[j + 1]) % 10
        return a[0]