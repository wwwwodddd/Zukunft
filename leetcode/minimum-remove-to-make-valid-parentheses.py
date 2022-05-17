class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        a = list(s)
        t = []
        for i in range(len(a)):
            if a[i] == '(':
                t.append(i)
            elif a[i] == ')':
                if t:
                    t.pop()
                else:
                    a[i] = ''
        for i in t:
            a[i] = ''
        return ''.join(a)