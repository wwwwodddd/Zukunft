class Solution:
    def numberOfLines(self, w: List[int], s: str) -> List[int]:
        c, d = 0, 100
        for i in s:
            x = w[ord(i)-97]
            if d + x > 100:
                d = x
                c += 1
            else:
                d += x
        return [c, d]