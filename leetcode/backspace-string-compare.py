class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def zuo(s):
            z = []
            for i in s:
                if i == '#':
                    if len(z):
                        z.pop()
                else:
                    z.append(i)
            return ''.join(z)
        return zuo(s)==zuo(t)
