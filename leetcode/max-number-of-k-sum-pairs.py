class Solution:
    def maxOperations(self, a: List[int], k: int) -> int:
        c = Counter(a)
        z = 0
        for i in c:
            if i < k - i:
                z += min(c[i], c[k - i])
            elif i == k - i:
                z += c[i] // 2
        return z