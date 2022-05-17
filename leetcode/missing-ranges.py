class Solution:
    def findMissingRanges(self, a: List[int], lower: int, upper: int) -> List[str]:
        a = [lower - 1] + a + [upper + 1]
        b = []
        for i in range(1, len(a)):
            if a[i - 1] + 1 == a[i] - 1:
                b.append('%d' % (a[i] - 1))            
            elif a[i - 1] + 1 < a[i] - 1:
                b.append('%d->%d' % (a[i - 1] + 1, a[i] - 1))
        return b