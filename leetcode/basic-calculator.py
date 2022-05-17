class Solution:
    def calculate(self, s: str) -> int:
        l = {'+':0,'-':0,'*':1,'/':1,'(':-1,')':-1}
        v = []
        o = []
        s = '('+s+')'
        i = 0
        f = 0
        while i < len(s):
            if s[i].isdigit():
                p = 0
                while s[i].isdigit():
                    p = p * 10 + int(s[i])
                    i += 1
                v.append(p)
                f=1
            elif s[i] in l:
                if f==0 and s[i]=='-':
                    v.append(0)
                if s[i]!=')':
                    f = 0
                if s[i]=='(':
                    o.append(s[i])
                else:
                    while len(o) and l[o[-1]] >= l[s[i]]:
                        if o[-1]=='(' and s[i]==')':
                            o.pop()
                            break
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
                    else:
                        o.append(s[i])
                i += 1
            else:
                i += 1
        return v[0]