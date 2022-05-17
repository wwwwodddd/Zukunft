class Solution:
    def summaryRanges(self, a: List[int]) -> List[str]:
        s = 0
        z = []
        for i in range(len(a)):
            if i + 1 == len(a) or a[i] + 1 < a[i + 1]:
                if a[s] == a[i]:
                    z.append(str(a[s]))
                else:
                    z.append('%d->%d' % (a[s], a[i]))
                s = i + 1
        return z