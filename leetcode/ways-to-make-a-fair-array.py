class Solution:
    def waysToMakeFair(self, a: List[int]) -> int:
        be = sum(a[0::2])
        bo = sum(a[1::2])
        fe = 0
        fo = 0
        z = 0
        for i in range(len(a)):
            if i % 2 == 0:
                be -= a[i]
            else:
                bo -= a[i]
            if fe + bo == fo + be:
                z += 1
            if i % 2 == 0:
                fe += a[i]
            else:
                fo += a[i]
        return z