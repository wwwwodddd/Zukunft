class Solution:
    def kSmallestPairs(self, a: List[int], b: List[int], k: int) -> List[List[int]]:
        c = []
        for i in range(len(a)):
            for j in range(len(b)):
                if (i+1) * (j+1) <= k:
                    c.append((a[i], b[j]))
                else:
                    break
        c.sort(key=lambda d:d[0]+d[1])
        return c[:k]