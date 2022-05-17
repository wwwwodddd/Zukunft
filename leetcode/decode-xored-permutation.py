class Solution:
    def decode(self, a: List[int]) -> List[int]:
        b = []
        z = 0
        for i in range(1, len(a) + 2):
            z ^= i
        for i in a[1::2]:
            z ^= i
        b.append(z)
        for i in a:
            b.append(b[-1] ^ i)
        return b