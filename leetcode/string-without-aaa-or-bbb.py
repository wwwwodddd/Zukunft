class Solution:
    def strWithout3a3b(self, a: int, b: int) -> str:
        if a > b:
            s = ['' for i in range(b + 1)]
            for i in range(a):
                s[i % (b + 1)] += 'a'
            for i in range(b):
                s[i] += 'b'
        else:
            s = ['' for i in range(a + 1)]
            for i in range(b):
                s[i % (a + 1)] += 'b'
            for i in range(a):
                s[i] += 'a'
        return ''.join(s)