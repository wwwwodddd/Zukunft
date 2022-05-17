class Solution:
    def thousandSeparator(self, n: int) -> str:
        if len(str(n)) > 3:
            return self.thousandSeparator(str(n)[:-3]) + '.' + str(n)[-3:]
        else:
            return str(n)