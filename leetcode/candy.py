class Solution:
    def candy(self, r: List[int]) -> int:
        a = [1 for i in r]
        for i in range(1, len(r)):
            if r[i] > r[i - 1]:
                a[i] = a[i - 1] + 1
        for i in range(1, len(r))[::-1]:
            if r[i - 1] > r[i]:
                a[i - 1] = max(a[i - 1], a[i] + 1)
        return sum(a)