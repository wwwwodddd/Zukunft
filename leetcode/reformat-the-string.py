class Solution:
    def reformat(self, s: str) -> str:
        a = b = ''
        for i in s:
            if i.isalpha():
                a += i
            else:
                b += i
        if len(a) < len(b):
            a, b = b, a
        if len(a) - len(b) > 1:
            return ''
        z = ''
        for i in range(len(a)):
            z += a[i]
            if i < len(b):
                z += b[i]
        return z