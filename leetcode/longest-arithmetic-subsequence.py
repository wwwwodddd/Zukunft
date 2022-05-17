class Solution:
    def longestArithSeqLength(self, a: List[int]) -> int:
        f = Counter()
        for i in range(len(a)):
            for j in range(i):
                f[(i,a[i]-a[j])] = max(f[(i,a[i]-a[j])],f[(j,a[i]-a[j])]+1,2)
        return max(f.values())