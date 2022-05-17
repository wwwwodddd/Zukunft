class Solution:
    def getWinner(self, a: List[int], k: int) -> int:
        n = len(a)
        i = 0
        c = 0
        for j in range(1, len(a)):
            if a[i] > a[j]:
                c += 1
            else:
                i = j
                c = 1
            if c == k:
                return a[i]
        return a[i]