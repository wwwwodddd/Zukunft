class Solution:
    def findPermutation(self, s: str) -> List[int]:
        a = s.split('I')
        z = []
        p = 1
        for i in a:
            for j in range(len(i)+1)[::-1]:
                z.append(p + j)
            p += len(i) + 1
        return z