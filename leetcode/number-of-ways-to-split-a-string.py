class Solution:
    def numWays(self, s: str) -> int:
        p = 1000000007
        n = len(s)
        if '1' not in s:
            return (n-1) * (n-2) // 2 % p
        else:
            a = s.split('1')
            if len(a) % 3 != 1:
                return 0
            return (len(a[len(a) // 3]) + 1) * (len(a[len(a) // 3 * 2]) + 1) % p