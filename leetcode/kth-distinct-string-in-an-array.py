class Solution:
    def kthDistinct(self, a: List[str], k: int) -> str:
        c = Counter(a)
        a = [i for i in c if c[i]==1]
        if len(a) < k:
            return ''
        return a[k - 1]