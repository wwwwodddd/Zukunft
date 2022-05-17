class FindSumPairs:
    def __init__(self, a: List[int], b: List[int]):
        self.a = a
        self.b = b
        self.c = Counter(b)
        

    def add(self, i: int, v: int) -> None:
        self.c[self.b[i]] -= 1
        self.b[i] += v
        self.c[self.b[i]] += 1

    def count(self, tot: int) -> int:
        z = 0
        for i in self.a:
            z += self.c[tot - i]
        return z


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)