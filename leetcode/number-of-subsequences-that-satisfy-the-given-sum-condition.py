class Solution:
    def numSubseq(self, a: List[int], t: int) -> int:
        a.sort()
        z = 0
        j = len(a) - 1
        p = 1000000007
        for i in range(len(a)):
            while i <= j and a[i] + a[j] > t:
                j -= 1
            if j < i:
                break
            z = (z + pow(2, j - i, p)) % p
        return z