class Solution:
    def largestValsFromLabels(self, a: List[int], b: List[int], numWanted: int, useLimit: int) -> int:
        d = defaultdict(list)
        for i in range(len(a)):
            d[b[i]].append(a[i])
        c = []
        for i in d:
            c += sorted(d[i])[-useLimit:]
        return sum(sorted(c)[-numWanted:])