class Solution:
    def numberOfBeams(self, b: List[str]) -> int:
        l = 0
        z = 0
        for i in b:
            if c := i.count('1'):
                z += l * c
                l = c
        return z
                