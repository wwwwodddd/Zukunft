class SparseVector:
    def __init__(self, a: List[int]):
        self.a = {}
        for i in range(len(a)):
            if a[i]:
                self.a[i] = a[i]

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, v: 'SparseVector') -> int:
        z = 0
        for i in self.a:
            if i in v.a:
                z += self.a[i] * v.a[i]
        return z
# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)