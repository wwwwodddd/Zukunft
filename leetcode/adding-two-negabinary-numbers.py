class Solution:
    def addNegabinary(self, a: List[int], b: List[int]) -> List[int]:
        a = a[::-1]
        b = b[::-1]
        if len(a) < len(b):
            a, b = b, a
        for i in range(len(b)):
            a[i] += b[i]
        for i in range(2):
            a.append(0)
        for i in range(len(a) - 2):
            while a[i] >= 2:
                a[i] -= 2
                if a[i + 1]:
                    a[i + 1] -= 1
                else:
                    a[i + 1] += 1
                    a[i + 2] += 1
        while len(a) > 1 and a[-1] == 0:
            a.pop()
        return a[::-1]