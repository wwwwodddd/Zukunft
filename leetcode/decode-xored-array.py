class Solution:
    def decode(self, a: List[int], k: int) -> List[int]:
        b=[k]
        for i in a:
            k^=i
            b.append(k)
        return b