class Solution:
    def corpFlightBookings(self, b: List[List[int]], n: int) -> List[int]:
        a = [0] * (n + 1)
        for x, y, z in b:
            a[x - 1] += z
            a[y] -= z
        for i in range(n):
            a[i + 1] += a[i]
        a.pop()
        return a