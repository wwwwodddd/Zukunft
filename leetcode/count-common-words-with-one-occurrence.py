class Solution:
    def countWords(self, a: List[str], b: List[str]) -> int:
        a = Counter(a)
        b = Counter(b)
        return sum(a[i]==1 and b[i]==1 for i in a)
