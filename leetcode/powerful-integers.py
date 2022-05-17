class Solution:
    def powerfulIntegers(self, x: int, y: int, b: int) -> List[int]:
        s = set()
        i = 1
        while i <= b:
            j = 1
            while i + j <= b:
                s.add(i + j)
                j *= y
                if j == 1:
                    break
            i *= x
            if i == 1:
                break
        return list(s)