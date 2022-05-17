class Solution:
    def slowestKey(self, a: List[int], s: str) -> str:
        z = 0
        zc = ''
        l = 0
        for i in range(len(a)):
            z, zc = max((z, zc), (a[i] - l, s[i]))
            l = a[i]
        return zc