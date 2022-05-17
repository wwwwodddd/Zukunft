class Solution:
    def largestMultipleOfThree(self, a: List[int]) -> str:
        s = sum(a)
        c = [0 for i in range(10)]
        for i in a:
            c[i] += 1
        def zuo():
            s = ''
            for i in range(10)[::-1]:
                s += str(i) * c[i]
            if s == '':
                return s
            return str(int(s))
        if s % 3 == 0:
            return zuo()
        for i in range(10):
            c[i] -= 1
            if c[i] >= 0 and (s - i) % 3 == 0:
                return zuo()
            c[i] += 1
        for i in range(10):
            for j in range(i + 1):
                c[i] -= 1
                c[j] -= 1
                if c[i] >= 0 and c[j] >= 0 and (s - i - j) % 3 == 0:
                    return zuo()
                c[j] += 1
                c[i] += 1
        return ''
        