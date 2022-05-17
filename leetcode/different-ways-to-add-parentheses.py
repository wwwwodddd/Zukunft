class Solution:
    g = {}
    def diffWaysToCompute(self, s: str) -> List[int]:
        if s in self.g:
            return self.g[s]
        z = []
        if s.isdigit():
            z.append(int(s))
        else:
            for i in range(1, len(s)):
                if s[i] in '+-*':
                    x = self.diffWaysToCompute(s[:i])
                    y = self.diffWaysToCompute(s[i+1:])
                    if s[i] == '+':
                        for j in x:
                            for k in y:
                                z.append(j + k)
                    if s[i] == '-':
                        for j in x:
                            for k in y:
                                z.append(j - k)
                    if s[i] == '*':
                        for j in x:
                            for k in y:
                                z.append(j * k)
        self.g[s] = z
        return z