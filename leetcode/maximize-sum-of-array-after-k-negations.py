class Solution:
    def largestSumAfterKNegations(self, a: List[int], k: int) -> int:
        a = sorted(a)
        i = 0
        while i < len(a) and k > 0:
            if a[i] < 0:
                a[i] = -a[i]
                i += 1
                k -= 1
            else:
                break
        a = sorted(a)
        if k & 1:
            a[0] = -a[0]
        return sum(a)