class Solution:
    def leastInterval(self, a: List[str], n: int) -> int:
        c = Counter(Counter(a).values())
        return max((max(c)-1)*(n+1)+c[max(c)], len(a))