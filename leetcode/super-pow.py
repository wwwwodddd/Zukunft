class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        p = 1337
        r = 1
        for i in b[::-1]:
            r = r * pow(a, int(i), p) % p
            a = pow(a, 10, p)
        return r