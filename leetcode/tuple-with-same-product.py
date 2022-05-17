class Solution:
    def tupleSameProduct(self, a: List[int]) -> int:
        c = Counter()
        z = 0
        for i in range(len(a)):
            for j in range(i):
                z += c[a[i] * a[j]]
                c[a[i] * a[j]] += 1
        return 8 * z
                    