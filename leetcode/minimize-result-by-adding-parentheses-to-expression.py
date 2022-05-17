class Solution:
    def minimizeResult(self, s: str) -> str:
        b = s.split('+')
        z = eval(s)
        w = '(' + s + ')'
        for i in range(len(b[0])):
            for j in range(1,len(b[1])+1):
                t = int(b[0][i:]) + int(b[1][:j])
                if i > 0:
                    t *= int(b[0][:i])
                if j < len(b[1]):
                    t *= int(b[1][j:])
                if z > t:
                    z = t
                    w = b[0][:i] + '(' + b[0][i:] + '+' + b[1][:j] + ')' + b[1][j:]
        return w