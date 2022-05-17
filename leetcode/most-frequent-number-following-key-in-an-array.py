class Solution:
    def mostFrequent(self, a: List[int], x: int) -> int:
        c = Counter()
        for i in range(len(a) - 1):
            if a[i] == x:
                c[a[i + 1]] += 1
        return c.most_common(1)[0][0]