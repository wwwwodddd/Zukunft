class Solution:
    def mostCompetitive(self, a: List[int], k: int) -> List[int]:
        s = []
        for i in range(len(a)):
            while len(s) > 0 and s[-1] > a[i] and len(s) + len(a) - i > k:
                s.pop()
            s.append(a[i])
        return s[:k]