class Solution:
    def canCompleteCircuit(self, a: List[int], b: List[int]) -> int:
        for i in range(len(a)):
            a[i] -= b[i]
        a = [0] + a
        for i in range(1, len(a)):
            a[i] += a[i-1]
        if a[-1] < 0:
            return -1
        else:
            return a.index(min(a))