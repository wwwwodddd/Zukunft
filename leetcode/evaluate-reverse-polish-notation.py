class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        s = []
        for i in tokens:
            if i in '+-*/':
                y = s.pop()
                x = s.pop()
                if i == '+':
                    s.append(x + y)
                elif i == '-':
                    s.append(x - y)
                elif i == '*':
                    s.append(x * y)
                else:
                    z = abs(x) // abs(y)
                    if x < 0:
                        z = -z
                    if y < 0:
                        z = -z
                    s.append(z)
            else:
                s.append(int(i))
        return s[0]