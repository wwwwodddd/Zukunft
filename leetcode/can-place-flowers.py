class Solution:
    def canPlaceFlowers(self, a: List[int], n: int) -> bool:
        m = len(a)
        a = [0] + a + [0]
        for i in range(1, m + 1):
            if a[i] == 0 and a[i - 1] == 0 and a[i + 1] == 0:
                n -= 1
                a[i] = 1
        return n <= 0