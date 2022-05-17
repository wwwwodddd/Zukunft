class Solution:
    def numMusicPlaylists(self, n: int, m: int, k: int) -> int:
        p = 1000000007
        f = [[0 for j in range(m + 1)]for i in range(n + 1)]
        z = 0
        c = 1
        for i in range(1, n + 1)[::-1]:
            f = 1
            for j in range(m):
                f = f * (i - min(j, k)) % p
            if (n - i) % 2 == 0:
                z = (z + f * c) % p
            else:
                z = (z - f * c) % p
            c = c * i * pow(n - i + 1, p - 2, p) % p
        return z