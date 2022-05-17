class Solution:
    def firstDayBeenInAllRooms(self, a: List[int]) -> int:
        p = 1000000007
        n = len(a)
        s = [0 for i in range(n)]
        for i in range(n-1):
            s[i+1] = (2 * s[i] + 2 - s[a[i]]) % p
        return s[-1] % p