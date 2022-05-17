class Solution:
    def minimumKeypresses(self, s: str) -> int:
        c = sorted(Counter(s).values(), reverse=True)
        return sum(c[i] * (i // 9 + 1) for i in range(len(c)))