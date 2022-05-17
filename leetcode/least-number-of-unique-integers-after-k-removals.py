class Solution:
    def findLeastNumOfUniqueInts(self, a: List[int], k: int) -> int:
        c = Counter(a).most_common()
        z = len(c)
        for x, y in c[::-1]:
            if k >= y:
                k -= y
                z -= 1
        return z