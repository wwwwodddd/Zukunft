class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        s = self.countAndSay(n-1)
        t = ''
        c = 0
        l = ''
        for i in s:
            if i != l:
                if l != '':
                    t += str(c) + l
                l = i
                c = 1
            else:
                c += 1
        t += str(c) + l
        return t