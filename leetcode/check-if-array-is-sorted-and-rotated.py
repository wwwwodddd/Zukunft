class Solution:
    def check(self, a: List[int]) -> bool:
        c = 0
        for i in range(1, len(a)):
            if a[i-1] > a[i]:
                c += 1
        return c == 0 or c == 1 and a[-1] <= a[0]