class Solution:
    def calculate(self, s: str) -> int:
        l = {'+':0,'-':0,'*':1,'/':1}
        v = []
        o = []
        p = 0
        s += '+0'
        for i in s:
            if i.isdigit():
                p = p * 10 + int(i)
            elif i in l:
                v.append(p)
                p = 0
                while len(o) and l[o[-1]] >= l[i]:
                    y = v.pop()
                    x = v.pop()
                    if o[-1] == '+':
                        v.append(x + y)
                    elif o[-1] == '-':
                        v.append(x - y)
                    elif o[-1] == '*':
                        v.append(x * y)
                    elif o[-1] == '/':
                        v.append(x // y)
                    o.pop()
                o.append(i)
        return v[0]