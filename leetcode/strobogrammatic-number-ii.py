class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        a = [('', '')]
        for i in range(n // 2):
            b = []
            for x, y in a:
                for c, d in [('0', '0'), ('1', '1'), ('8', '8'), ('6', '9'), ('9', '6')]:
                    b.append((x + c, d + y))
            a = b
        z = []
        for x, y in a:
            if x.startswith('0'):
                continue
            if n & 1:
                for c in '018':
                    z.append(x + c + y)
            else:
                z.append(x + y)
        return z