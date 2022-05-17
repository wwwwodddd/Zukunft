class Solution:
    def indexPairs(self, s: str, t: List[str]) -> List[List[int]]:
        z = []
        for k in t:
            for i in range(len(k), len(s) + 1):
                if s[i - len(k) : i] == k:
                    z.append([i - len(k), i - 1])
        return sorted(z)